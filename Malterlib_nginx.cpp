
#include <Mib/Core/Core>

DMibAppNoClass;

extern "C"
{
	#include <ngx_core.h>
	
#ifdef DPlatformFamily_Linux
	void 
	ngx_free(void* mem)
	{
		free(mem);
	}

	void *
	ngx_alloc(size_t size, ngx_log_t *log)
	{
		return malloc(size);
	}

	void *
	ngx_calloc(size_t size, ngx_log_t *log)
	{
		return calloc(1, size);
	}

	void *
	ngx_memalign(size_t alignment, size_t size, ngx_log_t *log)
	{
		return memalign(size, alignment);
	}
#else
	void 
	ngx_free(void* mem)
	{
		fg_FreeNoSize(mem);
	}

	void *
	ngx_alloc(size_t size, ngx_log_t *log)
	{
		return fg_Alloc(size);
	}

	void *
	ngx_calloc(size_t size, ngx_log_t *log)
	{
		return fg_AllocInitZero(size);
	}

	void *
	ngx_memalign(size_t alignment, size_t size, ngx_log_t *log)
	{
		return fg_AllocAligned(size, alignment);
	}
#endif
}

struct CInit
{
	CInit()
	{
		NSys::fg_Process_AllowInvalidExit(true);
		fg_GetSys()->f_MemoryManager_DisableLeakReport(true);
	}
	
};

CInit g_Init;

#ifdef DPlatformFamily_Windows

int __cdecl wmain(int argc, wchar_t *argv[], wchar_t *envp[])
{
	DMibPDebugBreak;
	NSys::fg_Compiler_MakeActive(0, g_Init);
	return -1;
} 
int __stdcall wWinMain(struct HINSTANCE__ * hInstance, struct HINSTANCE__ * hPrevInstance, wchar_t *lpCmdLine,int nShowCmd)
{
	DMibPDebugBreak;
	return -1;
} 
/*
int __cdecl main(int argc, wchar_t *argv[])
{
} */
int __stdcall WinMain(struct HINSTANCE__ * hInstance, struct HINSTANCE__ * hPrevInstance, char *lpCmdLine,int nShowCmd)
{
	DMibPDebugBreak;
	return -1;
}

#endif
