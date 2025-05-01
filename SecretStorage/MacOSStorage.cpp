#include "SecretStorage.h"

#ifdef PLATFORM_MACOS

#define LLOG(x)    // RLOG("SecretStorage: " << x);
#define LTIMING(x) // RTIMING("SecretStorage::"  x);

namespace Upp {

bool SecretStorage::StorePassword(const String& key, const String& pwd)
{
	// TODO
	return false;
}

String SecretStorage::LoadPassword(const String& key)
{
	// TODO
	return String::GetVoid();
}

bool SecretStorage::DeletePassword(const String& key)
{
	// TODO
	return false;
}

}

#endif


