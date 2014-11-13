TARGET  = libJPEG.a
SRCS	= 	ckconfig  \
		jcapimin \
		jcapistd \
		jccoefct \
		jccolor \
		jcdctmgr \
		jchuff \
		jcinit \
		jcmainct \
		jcmarker \
		jcmaster \
		jcomapi \
		jcparam \
		jcphuff \
		jcprepct \
		jcsample \
		jctrans \
		jdapimin \
		jdapistd \
		jdatadst \
		jdatasrc \
		jdcoefct \
		jdcolor \
		jddctmgr \
		jdhuff \
		jdinput \
		jdmainct \
		jdmarker \
		jdmaster \
		jdmerge \
		jdphuff \
		jdpostct \
		jdsample \
		jdtrans \
		jerror \
		jfdctflt \
		jfdctfst \
		jfdctint \
		jidctflt \
		jidctfst \
		jidctint \
		jidctred \
		jmemmgr \
		jmemnobs \
		jquant1 \
		jquant2 \
		jutils 


CC   = g++
CFLAGS		+=
LFLAGS		+=

OBJECTS		= ${addsuffix .o, ${SRCS}}
CLEAN		= *.o ${TARGET}

#############################################################
all: debug

debug: CFLAGS += -DDEBUG -g3
debug: ${TARGET}

release: CFLAGS += -O2 -DRELEASE -pipe -fomit-frame-pointer
release: ${TARGET}

${TARGET}: depend ${OBJECTS} 
	ar r ${TARGET} ${OBJECTS}

clean:	
	/bin/rm -f ${CLEAN}

.cpp.o:
	${CC} ${CFLAGS} -c $<

depend: 
	makedepend -- ${CFLAGS} -- ${addsuffix .cpp, ${SRCS}}
# DO NOT DELETE

ckconfig.o: /usr/include/stdio.h /usr/include/features.h
ckconfig.o: /usr/include/stdc-predef.h /usr/include/libio.h
ckconfig.o: /usr/include/_G_config.h /usr/include/wchar.h
ckconfig.o: /usr/include/string.h /usr/include/xlocale.h
jcapimin.o: jinclude.h jconfig.h /usr/include/stdlib.h
jcapimin.o: /usr/include/features.h /usr/include/stdc-predef.h
jcapimin.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jcapimin.o: /usr/include/_G_config.h /usr/include/wchar.h
jcapimin.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jcapimin.o: jpegint.h jerror.h
jcapistd.o: jinclude.h jconfig.h /usr/include/stdlib.h
jcapistd.o: /usr/include/features.h /usr/include/stdc-predef.h
jcapistd.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jcapistd.o: /usr/include/_G_config.h /usr/include/wchar.h
jcapistd.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jcapistd.o: jpegint.h jerror.h
jccoefct.o: jinclude.h jconfig.h /usr/include/stdlib.h
jccoefct.o: /usr/include/features.h /usr/include/stdc-predef.h
jccoefct.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jccoefct.o: /usr/include/_G_config.h /usr/include/wchar.h
jccoefct.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jccoefct.o: jpegint.h jerror.h
jccolor.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jccolor.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jccolor.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jccolor.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jccolor.o: jpeglib.h jmorecfg.h jpegint.h jerror.h
jcdctmgr.o: jinclude.h jconfig.h /usr/include/stdlib.h
jcdctmgr.o: /usr/include/features.h /usr/include/stdc-predef.h
jcdctmgr.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jcdctmgr.o: /usr/include/_G_config.h /usr/include/wchar.h
jcdctmgr.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jcdctmgr.o: jpegint.h jerror.h jdct.h
jchuff.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jchuff.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jchuff.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jchuff.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jchuff.o: jpeglib.h jmorecfg.h jpegint.h jerror.h jchuff.h
jcinit.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jcinit.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jcinit.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jcinit.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jcinit.o: jpeglib.h jmorecfg.h jpegint.h jerror.h
jcmainct.o: jinclude.h jconfig.h /usr/include/stdlib.h
jcmainct.o: /usr/include/features.h /usr/include/stdc-predef.h
jcmainct.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jcmainct.o: /usr/include/_G_config.h /usr/include/wchar.h
jcmainct.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jcmainct.o: jpegint.h jerror.h
jcmarker.o: jinclude.h jconfig.h /usr/include/stdlib.h
jcmarker.o: /usr/include/features.h /usr/include/stdc-predef.h
jcmarker.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jcmarker.o: /usr/include/_G_config.h /usr/include/wchar.h
jcmarker.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jcmarker.o: jpegint.h jerror.h
jcmaster.o: jinclude.h jconfig.h /usr/include/stdlib.h
jcmaster.o: /usr/include/features.h /usr/include/stdc-predef.h
jcmaster.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jcmaster.o: /usr/include/_G_config.h /usr/include/wchar.h
jcmaster.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jcmaster.o: jpegint.h jerror.h
jcomapi.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jcomapi.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jcomapi.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jcomapi.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jcomapi.o: jpeglib.h jmorecfg.h jpegint.h jerror.h
jcparam.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jcparam.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jcparam.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jcparam.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jcparam.o: jpeglib.h jmorecfg.h jpegint.h jerror.h
jcphuff.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jcphuff.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jcphuff.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jcphuff.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jcphuff.o: jpeglib.h jmorecfg.h jpegint.h jerror.h jchuff.h
jcprepct.o: jinclude.h jconfig.h /usr/include/stdlib.h
jcprepct.o: /usr/include/features.h /usr/include/stdc-predef.h
jcprepct.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jcprepct.o: /usr/include/_G_config.h /usr/include/wchar.h
jcprepct.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jcprepct.o: jpegint.h jerror.h
jcsample.o: jinclude.h jconfig.h /usr/include/stdlib.h
jcsample.o: /usr/include/features.h /usr/include/stdc-predef.h
jcsample.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jcsample.o: /usr/include/_G_config.h /usr/include/wchar.h
jcsample.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jcsample.o: jpegint.h jerror.h
jctrans.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jctrans.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jctrans.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jctrans.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jctrans.o: jpeglib.h jmorecfg.h jpegint.h jerror.h
jdapimin.o: jinclude.h jconfig.h /usr/include/stdlib.h
jdapimin.o: /usr/include/features.h /usr/include/stdc-predef.h
jdapimin.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jdapimin.o: /usr/include/_G_config.h /usr/include/wchar.h
jdapimin.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jdapimin.o: jpegint.h jerror.h
jdapistd.o: jinclude.h jconfig.h /usr/include/stdlib.h
jdapistd.o: /usr/include/features.h /usr/include/stdc-predef.h
jdapistd.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jdapistd.o: /usr/include/_G_config.h /usr/include/wchar.h
jdapistd.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jdapistd.o: jpegint.h jerror.h
jdatadst.o: jinclude.h jconfig.h /usr/include/stdlib.h
jdatadst.o: /usr/include/features.h /usr/include/stdc-predef.h
jdatadst.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jdatadst.o: /usr/include/_G_config.h /usr/include/wchar.h
jdatadst.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jdatadst.o: jpegint.h jerror.h
jdatasrc.o: jinclude.h jconfig.h /usr/include/stdlib.h
jdatasrc.o: /usr/include/features.h /usr/include/stdc-predef.h
jdatasrc.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jdatasrc.o: /usr/include/_G_config.h /usr/include/wchar.h
jdatasrc.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jdatasrc.o: jpegint.h jerror.h
jdcoefct.o: jinclude.h jconfig.h /usr/include/stdlib.h
jdcoefct.o: /usr/include/features.h /usr/include/stdc-predef.h
jdcoefct.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jdcoefct.o: /usr/include/_G_config.h /usr/include/wchar.h
jdcoefct.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jdcoefct.o: jpegint.h jerror.h
jdcolor.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jdcolor.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jdcolor.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jdcolor.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jdcolor.o: jpeglib.h jmorecfg.h jpegint.h jerror.h
jddctmgr.o: jinclude.h jconfig.h /usr/include/stdlib.h
jddctmgr.o: /usr/include/features.h /usr/include/stdc-predef.h
jddctmgr.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jddctmgr.o: /usr/include/_G_config.h /usr/include/wchar.h
jddctmgr.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jddctmgr.o: jpegint.h jerror.h jdct.h
jdhuff.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jdhuff.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jdhuff.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jdhuff.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jdhuff.o: jpeglib.h jmorecfg.h jpegint.h jerror.h jdhuff.h
jdinput.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jdinput.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jdinput.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jdinput.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jdinput.o: jpeglib.h jmorecfg.h jpegint.h jerror.h
jdmainct.o: jinclude.h jconfig.h /usr/include/stdlib.h
jdmainct.o: /usr/include/features.h /usr/include/stdc-predef.h
jdmainct.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jdmainct.o: /usr/include/_G_config.h /usr/include/wchar.h
jdmainct.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jdmainct.o: jpegint.h jerror.h
jdmarker.o: jinclude.h jconfig.h /usr/include/stdlib.h
jdmarker.o: /usr/include/features.h /usr/include/stdc-predef.h
jdmarker.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jdmarker.o: /usr/include/_G_config.h /usr/include/wchar.h
jdmarker.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jdmarker.o: jpegint.h jerror.h
jdmaster.o: jinclude.h jconfig.h /usr/include/stdlib.h
jdmaster.o: /usr/include/features.h /usr/include/stdc-predef.h
jdmaster.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jdmaster.o: /usr/include/_G_config.h /usr/include/wchar.h
jdmaster.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jdmaster.o: jpegint.h jerror.h
jdmerge.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jdmerge.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jdmerge.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jdmerge.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jdmerge.o: jpeglib.h jmorecfg.h jpegint.h jerror.h
jdphuff.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jdphuff.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jdphuff.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jdphuff.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jdphuff.o: jpeglib.h jmorecfg.h jpegint.h jerror.h jdhuff.h
jdpostct.o: jinclude.h jconfig.h /usr/include/stdlib.h
jdpostct.o: /usr/include/features.h /usr/include/stdc-predef.h
jdpostct.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jdpostct.o: /usr/include/_G_config.h /usr/include/wchar.h
jdpostct.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jdpostct.o: jpegint.h jerror.h
jdsample.o: jinclude.h jconfig.h /usr/include/stdlib.h
jdsample.o: /usr/include/features.h /usr/include/stdc-predef.h
jdsample.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jdsample.o: /usr/include/_G_config.h /usr/include/wchar.h
jdsample.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jdsample.o: jpegint.h jerror.h
jdtrans.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jdtrans.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jdtrans.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jdtrans.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jdtrans.o: jpeglib.h jmorecfg.h jpegint.h jerror.h
jerror.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jerror.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jerror.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jerror.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jerror.o: jpeglib.h jmorecfg.h jpegint.h jerror.h jversion.h
jfdctflt.o: jinclude.h jconfig.h /usr/include/stdlib.h
jfdctflt.o: /usr/include/features.h /usr/include/stdc-predef.h
jfdctflt.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jfdctflt.o: /usr/include/_G_config.h /usr/include/wchar.h
jfdctflt.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jfdctflt.o: jpegint.h jerror.h jdct.h
jfdctfst.o: jinclude.h jconfig.h /usr/include/stdlib.h
jfdctfst.o: /usr/include/features.h /usr/include/stdc-predef.h
jfdctfst.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jfdctfst.o: /usr/include/_G_config.h /usr/include/wchar.h
jfdctfst.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jfdctfst.o: jpegint.h jerror.h jdct.h
jfdctint.o: jinclude.h jconfig.h /usr/include/stdlib.h
jfdctint.o: /usr/include/features.h /usr/include/stdc-predef.h
jfdctint.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jfdctint.o: /usr/include/_G_config.h /usr/include/wchar.h
jfdctint.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jfdctint.o: jpegint.h jerror.h jdct.h
jidctflt.o: jinclude.h jconfig.h /usr/include/stdlib.h
jidctflt.o: /usr/include/features.h /usr/include/stdc-predef.h
jidctflt.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jidctflt.o: /usr/include/_G_config.h /usr/include/wchar.h
jidctflt.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jidctflt.o: jpegint.h jerror.h jdct.h
jidctfst.o: jinclude.h jconfig.h /usr/include/stdlib.h
jidctfst.o: /usr/include/features.h /usr/include/stdc-predef.h
jidctfst.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jidctfst.o: /usr/include/_G_config.h /usr/include/wchar.h
jidctfst.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jidctfst.o: jpegint.h jerror.h jdct.h
jidctint.o: jinclude.h jconfig.h /usr/include/stdlib.h
jidctint.o: /usr/include/features.h /usr/include/stdc-predef.h
jidctint.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jidctint.o: /usr/include/_G_config.h /usr/include/wchar.h
jidctint.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jidctint.o: jpegint.h jerror.h jdct.h
jidctred.o: jinclude.h jconfig.h /usr/include/stdlib.h
jidctred.o: /usr/include/features.h /usr/include/stdc-predef.h
jidctred.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jidctred.o: /usr/include/_G_config.h /usr/include/wchar.h
jidctred.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jidctred.o: jpegint.h jerror.h jdct.h
jmemmgr.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jmemmgr.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jmemmgr.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jmemmgr.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jmemmgr.o: jpeglib.h jmorecfg.h jpegint.h jerror.h jmemsys.h
jmemnobs.o: jinclude.h jconfig.h /usr/include/stdlib.h
jmemnobs.o: /usr/include/features.h /usr/include/stdc-predef.h
jmemnobs.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
jmemnobs.o: /usr/include/_G_config.h /usr/include/wchar.h
jmemnobs.o: /usr/include/string.h /usr/include/xlocale.h jpeglib.h jmorecfg.h
jmemnobs.o: jpegint.h jerror.h jmemsys.h
jquant1.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jquant1.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jquant1.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jquant1.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jquant1.o: jpeglib.h jmorecfg.h jpegint.h jerror.h
jquant2.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jquant2.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jquant2.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jquant2.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jquant2.o: jpeglib.h jmorecfg.h jpegint.h jerror.h
jutils.o: jinclude.h jconfig.h /usr/include/stdlib.h /usr/include/features.h
jutils.o: /usr/include/stdc-predef.h /usr/include/alloca.h
jutils.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
jutils.o: /usr/include/wchar.h /usr/include/string.h /usr/include/xlocale.h
jutils.o: jpeglib.h jmorecfg.h jpegint.h jerror.h
