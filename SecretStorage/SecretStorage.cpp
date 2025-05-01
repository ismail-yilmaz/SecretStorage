#include "SecretStorage.h"

#define LLOG(x)    // RLOG("SecretStorage: " << x);
#define LTIMING(x) // RTIMING("SecretStorage::"  x);

namespace Upp {

bool SecretStorage::StoreBlob(const String& key, const String& blob)
{
	LTIMING("StoreBlob");
	
	if(String s = ZCompress(blob); s.IsVoid()) {
		err = t_("Unable to compress blob");
		return false;
	}
	else
		return StorePassword(key, Base64Encode(s));
}

String SecretStorage::LoadBlob(const String& key)
{
	LTIMING("LoadBlob");
	
	if(String s = LoadPassword(key); s.IsVoid()) {
		return String::GetVoid();
	}
	else
	if(s = ZDecompress(Base64Decode(s)); s.IsVoid()) {
		err = t_("Unable to decompress blob");
		return String::GetVoid();
	}
	else
		return s;
}

bool SecretStorage::DeleteBlob(const String& key)
{
	LTIMING("DeleteBlob");
	
	return DeletePassword(key);
}

}

