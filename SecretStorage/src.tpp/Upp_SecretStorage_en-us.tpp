topic "SecretStorage";
[i448;a25;kKO9;2 $$1,0#37138531426314131252341829483380:class]
[l288;2 $$2,2#27521748481378242620020725143825:desc]
[0 $$3,0#96390100711032703541132217272105:end]
[H6;0 $$4,0#05600065144404261032431302351956:begin]
[i448;a25;kKO9;2 $$5,0#37138531426314131252341829483370:item]
[l288;a4;*@5;1 $$6,6#70004532496200323422659154056402:requirement]
[l288;i1121;b17;O9;~~~.1408;2 $$7,0#10431211400427159095818037425705:param]
[i448;b42;O9;2 $$8,8#61672508125594000341940100500538:tparam]
[b42;2 $$9,9#13035079074754324216151401829390:normal]
[2 $$0,0#00000000000000000000000000000000:Default]
[{_} 
[ {{10000@(113.42.0) [s0;%% [*@7;4 SecretStorage]]}}&]
[s1; &]
[s1;:Upp`:`:SecretStorage: [*3 SecretStorage][3  ][@(0.0.255)3 :][3  Moveable<][*3 SecretStorage
][3 >]&]
[s2;%% This class provides a cross`-platform interface for securely 
storing and retrieving sensitive data such as passwords and blobs. 
It leverages native secure storage facilities on Linux (libsecret), 
Windows (Credential Manager), and macOS (Keychain Services).&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Constructor detail]]}}&]
[s3; &]
[s5;:Upp`:`:SecretStorage`:`:SecretStorage`(`): [* SecretStorage]()&]
[s2;%% Default constructor.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:SecretStorage`:`:`~`(`): [* `~SecretStorage]()&]
[s2;%% Destructor.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Public Method List]]}}&]
[s3; &]
[s5;:Upp`:`:SecretStorage`:`:GetPathName`(`): [@(0.0.255) static] String 
[* GetPathName]()&]
[s2;%% Returns a fixed identifier string for namespacing secrets. 
Default value is [C@3 org.Upp.SecretStorage].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:SecretStorage`:`:StorePassword`(const String`&`,const String`&`): [@(0.0.255) b
ool] [* StorePassword]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 key], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 pwd])&]
[s0;l288;%% Stores a string [%-*@3 password] securely under a given 
[%-*@3 key] . Returns true on success, false on failure. Use [^topic`:`/`/SecretStorage`/src`/Upp`_SecretStorage`_en`-us`#Upp`:`:SecretStorage`:`:GetErrorDesc`(`)const^ G
etErrorDesc()] to obtain the error message.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:SecretStorage`:`:LoadPassword`(const String`&`): String 
[* LoadPassword]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 key])&]
[s0;l288;%% Retrieves the password stored under the given [%-*@3 key]. 
Returns the password on success or String`::GetVoid() on failure. 
Use [^topic`:`/`/SecretStorage`/src`/Upp`_SecretStorage`_en`-us`#Upp`:`:SecretStorage`:`:GetErrorDesc`(`)const^ G
etErrorDesc()] to obtain the error message.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:SecretStorage`:`:DeletePassword`(const String`&`): [@(0.0.255) bool] 
[* DeletePassword]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 key])&]
[s2;%% Removes the password stored under the given [%-*@3 key] from 
the secure storage. Returns true on success, false on failure. 
Use [^topic`:`/`/SecretStorage`/src`/Upp`_SecretStorage`_en`-us`#Upp`:`:SecretStorage`:`:GetErrorDesc`(`)const^ G
etErrorDesc()] to obtain the error message.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:SecretStorage`:`:StoreBlob`(const String`&`,const String`&`): [@(0.0.255) b
ool] [* StoreBlob]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 key], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 blob])&]
[s2;%% Stores an arbitrary [%-*@3 blob]  securely under a given [%-*@3 key]. 
The blob will be compressed (Z) and encoded (base64) internally 
before stored. Returns true on success, false on failure. Use 
[^topic`:`/`/SecretStorage`/src`/Upp`_SecretStorage`_en`-us`#Upp`:`:SecretStorage`:`:GetErrorDesc`(`)const^ G
etErrorDesc()] to obtain the error message.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:SecretStorage`:`:LoadBlob`(const String`&`): String [* LoadBlob]([@(0.0.255) c
onst] String[@(0.0.255) `&] [*@3 key])&]
[s2;%% Retrieves the arbitrary blob stored under the given [%-*@3 key]. 
Returns the decompressed (Z) and decoded (base64) blob on success 
or String`::GetVoid() on failure. Use [^topic`:`/`/SecretStorage`/src`/Upp`_SecretStorage`_en`-us`#Upp`:`:SecretStorage`:`:GetErrorDesc`(`)const^ G
etErrorDesc()] to obtain the error message.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:SecretStorage`:`:DeleteBlob`(const String`&`): [@(0.0.255) bool] 
[* DeleteBlob]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 key])&]
[s2;%% Removes the blob stored under the given [%-*@3 key] from the 
secure storage. Returns true on success, false on failure. Use 
[^topic`:`/`/SecretStorage`/src`/Upp`_SecretStorage`_en`-us`#Upp`:`:SecretStorage`:`:GetErrorDesc`(`)const^ G
etErrorDesc()] to obtain the error message.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:SecretStorage`:`:GetErrorDesc`(`)const: String [* GetErrorDesc]() 
[@(0.0.255) const]&]
[s0;l288;%% Returns the last error message if an operation failed. 
If no error occurred, returns Null.&]
[s3;%% ]]