#include "SecretStorage.h"

#ifdef PLATFORM_WIN32

#include <wincred.h>
#pragma comment(lib, "advapi32.lib")

#define LLOG(x)    // RLOG("SecretStorage: " << x);
#define LTIMING(x) // RTIMING("SecretStorage::"  x);

namespace Upp {

static String MakeErrorMsg(const String& txt)
{
	String e = Format("%s (%s: %d)", txt, t_("Error code"), (int) GetLastError());
	LLOG(e);
	return txt;
}

bool SecretStorage::StorePassword(const String& key, const String& pwd)
{
	LTIMING("StorePassword");
	
	err = Null;
	Vector<WCHAR> k = ToSystemCharsetW(key);

	CREDENTIALW credentials = { 0 };
	credentials.Type = CRED_TYPE_GENERIC;
	credentials.TargetName = k;
	credentials.CredentialBlobSize = (DWORD) pwd.GetLength();
	credentials.CredentialBlob = (LPBYTE) ~pwd;
	credentials.Persist = CRED_PERSIST_LOCAL_MACHINE;
	credentials.UserName = nullptr; // NOP

	if(!CredWriteW(&credentials, 0)) {
		err = MakeErrorMsg(t_("Failed storing secret"));
		return false;
	}

	return true;
}

String SecretStorage::LoadPassword(const String& key)
{
	LTIMING("LoadPassword");
	
	err = Null;
	PCREDENTIALW credentials = nullptr;
	if(CredReadW(ToSystemCharsetW(key), CRED_TYPE_GENERIC, 0, &credentials)) {
		String result(credentials->CredentialBlob, credentials->CredentialBlobSize);
		CredFree(credentials);
		return result;
	}

	err = MakeErrorMsg(t_("Failed retrieving secret"));
	return String::GetVoid();
}

bool SecretStorage::DeletePassword(const String& key)
{
	LTIMING("DeletePassword");
	
	err = Null;
	if(!CredDeleteW(ToSystemCharsetW(key), CRED_TYPE_GENERIC, 0)) {
		err = MakeErrorMsg(t_("Failed deleting secret"));
		return false;
	}
	return true;
}

}

#endif
