#include "Log.h"

void Log(const char *fmt, ...)
{
	va_list list;
	static char buffer[1024];
	static DWORD w;
	FILE *f;

	va_start(list, fmt);

	// To console
	DWORD len = wvsprintfA(buffer, fmt, list);
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), buffer, len, (DWORD *)&w, NULL);

	if (fopen_s(&f, "dinput8.log", "a+") == 0)
	{
		vfprintf(f, fmt, list);
		fflush(f);
		fclose(f);
	}

	va_end(list);
}

void Hexdump(void *ptr, int buflen)
{
	unsigned char *buf = (unsigned char*)ptr;
	int i, j;
	for (i = 0; i<buflen; i += 16) {
		Log("%06x: ", i);
		for (j = 0; j<16; j++)
			if (i + j < buflen)
				Log("%02x ", buf[i + j]);
			else
				Log("   ");
		Log(" ");
		for (j = 0; j<16; j++)
			if (i + j < buflen)
				Log("%c", isprint(buf[i + j]) ? buf[i + j] : '.');
		Log("\n");
	}
}