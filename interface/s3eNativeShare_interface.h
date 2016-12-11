/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef  s3eResult(*s3eNativeShareRegister_t)(s3eNativeShareCallback cbid, s3eCallback fn, void* userData);
typedef  s3eResult(*s3eNativeShareUnRegister_t)(s3eNativeShareCallback cbid, s3eCallback fn);
typedef  s3eResult(*s3eNativeShareShow_t)(const char* text, const char* url);

/**
 * struct that gets filled in by s3eNativeShareRegister
 */
typedef struct s3eNativeShareFuncs
{
    s3eNativeShareRegister_t m_s3eNativeShareRegister;
    s3eNativeShareUnRegister_t m_s3eNativeShareUnRegister;
    s3eNativeShareShow_t m_s3eNativeShareShow;
} s3eNativeShareFuncs;
