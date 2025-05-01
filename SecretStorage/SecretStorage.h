#ifndef _Core_SecretStorage_h_
#define _Core_SecretStorage_h_

#include <Core/Core.h>

namespace Upp {

class SecretStorage : Moveable<SecretStorage> {
public:
    SecretStorage()                                                  {}
    virtual ~SecretStorage()                                         {}

    virtual String GetPathName() const                               { return String("org.Upp.SecretStorage"); }
    
    bool    StorePassword(const String& key, const String& pwd);
    String  LoadPassword(const String& key);
    bool    DeletePassword(const String& key);

    bool    StoreBlob(const String& key, const String& blob);
    String  LoadBlob(const String& key);
    bool    DeleteBlob(const String& key);

    String  GetErrorDesc()const                                      { return err; }
    
    hash_t  GetHashValue() const                                     { return GetPathName().GetHashValue(); }
    
private:
	String  MakeKey(const String& key)                               { return UnixPath(AppendFileName(GetPathName(), key)); }
	
    String err;
};

}
#endif
