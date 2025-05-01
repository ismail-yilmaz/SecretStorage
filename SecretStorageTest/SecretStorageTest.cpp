#include <Core/Core.h>
#include <SecretStorage/SecretStorage.h>

using namespace Upp;

CONSOLE_APP_MAIN
{
	StdLogSetup(LOG_FILE);

	SecretStorage store;
	
	const String key = "SecretStorageExample";
	const String pwd = "examplepassword1234567890", wrongkey = "aaba", wrongpwd = "2343";
	{
		// Should not fail
		DUMP(store.StorePassword(key, pwd));
		DUMP(store.LoadPassword(key) == pwd);
		DUMP(store.DeletePassword(key));
		DUMP(store.StoreBlob(key, pwd));
		DUMP(store.LoadBlob(key) == pwd);
		DUMP(store.DeleteBlob(key));
	}
	DUMP(store.StorePassword(key, pwd));
	{
		// Should fail
		DUMP(store.LoadPassword(key) == wrongpwd);
		DUMP(store.LoadPassword(wrongkey) == pwd);
		DUMP(store.DeletePassword(wrongkey));
	}
	DUMP(store.DeletePassword(key));
	DUMP(store.StoreBlob(key, pwd));
	{
		// Should fail
		DUMP(store.LoadBlob(key) == wrongpwd);
		DUMP(store.LoadBlob(wrongkey) == pwd);
		DUMP(store.DeleteBlob(wrongkey));
	}

	DUMP(store.DeleteBlob(key));

	CheckLogEtalon();
}
