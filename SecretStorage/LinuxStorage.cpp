#include "SecretStorage.h"

#ifdef PLATFORM_LINUX

#include <glib.h>
#include <libsecret/secret.h>

#define LLOG(x)    // RLOG("SecretStorage: " << x);
#define LTIMING(x) // RTIMING("SecretStorage::"  x);

namespace Upp {

static const SecretSchema* GetGenericSchema()
{
    static const SecretSchema schema = {
		"com.Upp.SecretStorage",
		SECRET_SCHEMA_NONE,
		{
			{
				"data", SECRET_SCHEMA_ATTRIBUTE_STRING
			},
			nullptr
		}
	};
    return &schema;
}

static String MakeErrorMsg(GError *error, const String& txt)
{
	ASSERT(error);
	String e = Format("%s (%s: %d)", txt, t_("Error code"), (int) error->code);
	g_error_free(error);
	LLOG(txt + ": " + e);
	return txt;
}

bool SecretStorage::StorePassword(const String& key, const String& pwd)
{
	err = Null;
	GError *error = nullptr;

	LTIMING("StorePassword");
	
	gboolean success = secret_password_store_sync(
		GetGenericSchema(),
		SECRET_COLLECTION_DEFAULT,
		~key,
		pwd,
		nullptr,
		&error,
		"data", ~key, nullptr);

	if(error)
		err = MakeErrorMsg(error, t_("Failed storing secret"));

	return success;
}

String SecretStorage::LoadPassword(const String& key)
{
	err = Null;
	GError* error = nullptr;

	LTIMING("LoadPassword");
	
	gchar* pwd = secret_password_lookup_sync(
		GetGenericSchema(),
		nullptr,
		&error,
		"data",~key, nullptr);
		
	if(error) {
		err = MakeErrorMsg(error, t_("Failed retrieving secret"));
		return String::GetVoid();
	}

	String result = pwd;
	secret_password_free(pwd);
	return result;
}

bool SecretStorage::DeletePassword(const String& key)
{
	err = Null;
	GError* error = nullptr;

	LTIMING("DeletePassword");
	
	gboolean success = secret_password_clear_sync(
		GetGenericSchema(),
		nullptr,
		&error,
		"data", ~key, nullptr);
		
	if(error)
		err = MakeErrorMsg(error, t_("Failed deleting secret"));

	return success;
}

}

#endif
