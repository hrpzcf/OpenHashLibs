#ifdef EXPORT_DLL_FUNCS
    #define DllExport __declspec(dllexport)
#else
    #define DllExport __declspec(dllimport)
#endif

#define CURRENT_VER "0.1.0";

DllExport const char *get_hashes_version(void);

const char *get_hashes_version(void)
{
    return CURRENT_VER;
}
