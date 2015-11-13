
Timersps.dll: dlldata.obj Timers_p.obj Timers_i.obj
	link /dll /out:Timersps.dll /def:Timersps.def /entry:DllMain dlldata.obj Timers_p.obj Timers_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del Timersps.dll
	@del Timersps.lib
	@del Timersps.exp
	@del dlldata.obj
	@del Timers_p.obj
	@del Timers_i.obj
