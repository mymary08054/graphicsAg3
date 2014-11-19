TARGET  = Assignment2
SRCS	= 	Util/time \
		Util/cmdLineParser \
		Util/geometry \
		Util/geometry.todo \
		Image/bmp \
		Image/image \
		Image/image.todo \
		Image/jpeg \
		Image/lineSegments \
		Image/lineSegments.todo \
		Ray/mouse \
		Ray/rayBox \
		Ray/rayBox.todo \
		Ray/rayCamera \
		Ray/rayCamera.todo \
		Ray/rayCone \
		Ray/rayCone.todo \
		Ray/rayCylinder \
		Ray/rayCylinder.todo \
		Ray/rayDirectionalLight \
		Ray/rayDirectionalLight.todo \
		Ray/rayFileInstance \
		Ray/rayGroup \
		Ray/rayGroup.todo \
		Ray/rayKey \
		Ray/rayPointLight \
		Ray/rayPointLight.todo \
		Ray/rayScene \
		Ray/rayScene.todo \
		Ray/raySphere \
		Ray/raySphere.todo \
		Ray/raySpotLight \
		Ray/raySpotLight.todo \
		Ray/rayTriangle \
		Ray/rayTriangle.todo \
		Ray/rayWindow \
		main

CC   = g++
CFLAGS		+= -I.
LFLAGS		+= -LJPEG -lJPEG -lglut -lGLU -lGL

OBJECTS		= ${addsuffix .o, ${SRCS}}
CLEAN		= *.o .depend ${TARGET} *.dsp *.dsw *.bak

#############################################################
all: debug

debug: CFLAGS += -DDEBUG -g3
debug: ${TARGET}

release: CFLAGS += -O2 -DRELEASE -pipe -fomit-frame-pointer
release: ${TARGET}

${TARGET}: depend JPEG/libJPEG.a ${OBJECTS}
	${CC} -o $@ ${OBJECTS} ${LFLAGS}

clean:	
	/bin/rm -f ${CLEAN}

.cpp.o:
	${CC} ${CFLAGS} -o $@ -c $<

JPEG/libJPEG.a:
	${MAKE} -C JPEG

depend: 
	makedepend -- ${CFLAGS} -- ${addsuffix .cpp, ${SRCS}}
# DO NOT DELETE

Util/time.o: /usr/include/stdlib.h /usr/include/features.h
Util/time.o: /usr/include/stdc-predef.h /usr/include/alloca.h
Util/cmdLineParser.o: /usr/include/stdio.h /usr/include/features.h
Util/cmdLineParser.o: /usr/include/stdc-predef.h /usr/include/libio.h
Util/cmdLineParser.o: /usr/include/_G_config.h /usr/include/wchar.h
Util/cmdLineParser.o: /usr/include/stdlib.h /usr/include/alloca.h
Util/cmdLineParser.o: /usr/include/string.h /usr/include/xlocale.h
Util/cmdLineParser.o: /usr/include/assert.h Util/cmdLineParser.h
Util/geometry.o: /usr/include/stdlib.h /usr/include/features.h
Util/geometry.o: /usr/include/stdc-predef.h /usr/include/alloca.h
Util/geometry.o: /usr/include/math.h ./SVD/SVDFit.h ./SVD/MatrixMNTC.h
Util/geometry.o: ./SVD/comdef.h ./SVD/MatrixMNTC.inl ./SVD/SVD.h
Util/geometry.o: ./SVD/SVD.inl /usr/include/stdio.h /usr/include/libio.h
Util/geometry.o: /usr/include/_G_config.h /usr/include/wchar.h
Util/geometry.o: /usr/include/memory.h /usr/include/string.h
Util/geometry.o: /usr/include/xlocale.h /usr/include/malloc.h
Util/geometry.o: ./SVD/SVDFit.inl ./SVD/MatrixMNTC.h Util/geometry.h
Util/geometry.todo.o: /usr/include/stdlib.h /usr/include/features.h
Util/geometry.todo.o: /usr/include/stdc-predef.h /usr/include/alloca.h
Util/geometry.todo.o: /usr/include/math.h ./SVD/SVDFit.h ./SVD/MatrixMNTC.h
Util/geometry.todo.o: ./SVD/comdef.h ./SVD/MatrixMNTC.inl ./SVD/SVD.h
Util/geometry.todo.o: ./SVD/SVD.inl /usr/include/stdio.h /usr/include/libio.h
Util/geometry.todo.o: /usr/include/_G_config.h /usr/include/wchar.h
Util/geometry.todo.o: /usr/include/memory.h /usr/include/string.h
Util/geometry.todo.o: /usr/include/xlocale.h /usr/include/malloc.h
Util/geometry.todo.o: ./SVD/SVDFit.inl ./SVD/MatrixMNTC.h Util/geometry.h
Image/bmp.o: Image/bmp.h Image/image.h /usr/include/stdio.h
Image/bmp.o: /usr/include/features.h /usr/include/stdc-predef.h
Image/bmp.o: /usr/include/libio.h /usr/include/_G_config.h
Image/bmp.o: /usr/include/wchar.h Image/lineSegments.h /usr/include/stdlib.h
Image/bmp.o: /usr/include/alloca.h
Image/image.o: /usr/include/string.h /usr/include/features.h
Image/image.o: /usr/include/stdc-predef.h /usr/include/xlocale.h
Image/image.o: /usr/include/stdlib.h /usr/include/alloca.h Image/image.h
Image/image.o: /usr/include/stdio.h /usr/include/libio.h
Image/image.o: /usr/include/_G_config.h /usr/include/wchar.h
Image/image.o: Image/lineSegments.h ./Util/cmdLineParser.h ./Image/bmp.h
Image/image.o: ./Image/jpeg.h
Image/image.todo.o: Image/image.h /usr/include/stdio.h
Image/image.todo.o: /usr/include/features.h /usr/include/stdc-predef.h
Image/image.todo.o: /usr/include/libio.h /usr/include/_G_config.h
Image/image.todo.o: /usr/include/wchar.h Image/lineSegments.h
Image/image.todo.o: /usr/include/stdlib.h /usr/include/alloca.h
Image/image.todo.o: /usr/include/math.h /usr/include/time.h
Image/image.todo.o: /usr/include/xlocale.h
Image/jpeg.o: Image/jpeg.h Image/image.h /usr/include/stdio.h
Image/jpeg.o: /usr/include/features.h /usr/include/stdc-predef.h
Image/jpeg.o: /usr/include/libio.h /usr/include/_G_config.h
Image/jpeg.o: /usr/include/wchar.h Image/lineSegments.h /usr/include/assert.h
Image/jpeg.o: /usr/include/stdlib.h /usr/include/alloca.h ./JPEG/jpeglib.h
Image/jpeg.o: ./JPEG/jconfig.h ./JPEG/jmorecfg.h /usr/include/setjmp.h
Image/lineSegments.o: Image/lineSegments.h /usr/include/stdio.h
Image/lineSegments.o: /usr/include/features.h /usr/include/stdc-predef.h
Image/lineSegments.o: /usr/include/libio.h /usr/include/_G_config.h
Image/lineSegments.o: /usr/include/wchar.h /usr/include/math.h
Image/lineSegments.todo.o: Image/lineSegments.h /usr/include/stdio.h
Image/lineSegments.todo.o: /usr/include/features.h /usr/include/stdc-predef.h
Image/lineSegments.todo.o: /usr/include/libio.h /usr/include/_G_config.h
Image/lineSegments.todo.o: /usr/include/wchar.h /usr/include/math.h
Ray/mouse.o: Ray/mouse.h /usr/include/GL/glut.h
Ray/mouse.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
Ray/mouse.o: /usr/include/GL/glext.h /usr/include/inttypes.h
Ray/mouse.o: /usr/include/features.h /usr/include/stdc-predef.h
Ray/mouse.o: /usr/include/stdint.h /usr/include/GL/glu.h
Ray/mouse.o: /usr/include/stdlib.h /usr/include/alloca.h ./Util/geometry.h
Ray/rayBox.o: /usr/include/stdio.h /usr/include/features.h
Ray/rayBox.o: /usr/include/stdc-predef.h /usr/include/libio.h
Ray/rayBox.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayBox.o: /usr/include/stdlib.h /usr/include/alloca.h /usr/include/math.h
Ray/rayBox.o: Ray/rayBox.h ./Util/geometry.h Ray/rayShape.h Ray/rayScene.h
Ray/rayBox.o: ./Image/image.h Image/lineSegments.h /usr/include/GL/glut.h
Ray/rayBox.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
Ray/rayBox.o: /usr/include/GL/glext.h /usr/include/inttypes.h
Ray/rayBox.o: /usr/include/stdint.h /usr/include/GL/glu.h Ray/rayLight.h
Ray/rayBox.o: Ray/rayGroup.h Ray/rayKey.h ./Util/parameterSamples.h
Ray/rayBox.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/rayBox.todo.o: /usr/include/math.h /usr/include/features.h
Ray/rayBox.todo.o: /usr/include/stdc-predef.h /usr/include/GL/glut.h
Ray/rayBox.todo.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
Ray/rayBox.todo.o: /usr/include/GL/glext.h /usr/include/inttypes.h
Ray/rayBox.todo.o: /usr/include/stdint.h /usr/include/GL/glu.h
Ray/rayBox.todo.o: /usr/include/stdlib.h /usr/include/alloca.h Ray/rayScene.h
Ray/rayBox.todo.o: ./Util/geometry.h ./Image/image.h /usr/include/stdio.h
Ray/rayBox.todo.o: /usr/include/libio.h /usr/include/_G_config.h
Ray/rayBox.todo.o: /usr/include/wchar.h Image/lineSegments.h Ray/rayShape.h
Ray/rayBox.todo.o: Ray/rayLight.h Ray/rayGroup.h Ray/rayKey.h
Ray/rayBox.todo.o: ./Util/parameterSamples.h ./Util/parameterSamples.todo.inl
Ray/rayBox.todo.o: Ray/rayCamera.h Ray/rayBox.h
Ray/rayCamera.o: Ray/rayCamera.h /usr/include/stdio.h /usr/include/features.h
Ray/rayCamera.o: /usr/include/stdc-predef.h /usr/include/libio.h
Ray/rayCamera.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayCamera.o: ./Util/geometry.h
Ray/rayCamera.todo.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
Ray/rayCamera.todo.o: /usr/include/GL/gl.h /usr/include/GL/glext.h
Ray/rayCamera.todo.o: /usr/include/inttypes.h /usr/include/features.h
Ray/rayCamera.todo.o: /usr/include/stdc-predef.h /usr/include/stdint.h
Ray/rayCamera.todo.o: /usr/include/GL/glu.h /usr/include/stdlib.h
Ray/rayCamera.todo.o: /usr/include/alloca.h /usr/include/math.h
Ray/rayCamera.todo.o: Ray/rayCamera.h /usr/include/stdio.h
Ray/rayCamera.todo.o: /usr/include/libio.h /usr/include/_G_config.h
Ray/rayCamera.todo.o: /usr/include/wchar.h ./Util/geometry.h
Ray/rayCone.o: /usr/include/stdio.h /usr/include/features.h
Ray/rayCone.o: /usr/include/stdc-predef.h /usr/include/libio.h
Ray/rayCone.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayCone.o: /usr/include/stdlib.h /usr/include/alloca.h
Ray/rayCone.o: /usr/include/math.h Ray/rayCone.h ./Util/geometry.h
Ray/rayCone.o: Ray/rayShape.h Ray/rayScene.h ./Image/image.h
Ray/rayCone.o: Image/lineSegments.h /usr/include/GL/glut.h
Ray/rayCone.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
Ray/rayCone.o: /usr/include/GL/glext.h /usr/include/inttypes.h
Ray/rayCone.o: /usr/include/stdint.h /usr/include/GL/glu.h Ray/rayLight.h
Ray/rayCone.o: Ray/rayGroup.h Ray/rayKey.h ./Util/parameterSamples.h
Ray/rayCone.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/rayCone.todo.o: /usr/include/math.h /usr/include/features.h
Ray/rayCone.todo.o: /usr/include/stdc-predef.h /usr/include/GL/glut.h
Ray/rayCone.todo.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
Ray/rayCone.todo.o: /usr/include/GL/glext.h /usr/include/inttypes.h
Ray/rayCone.todo.o: /usr/include/stdint.h /usr/include/GL/glu.h
Ray/rayCone.todo.o: /usr/include/stdlib.h /usr/include/alloca.h
Ray/rayCone.todo.o: Ray/rayScene.h ./Util/geometry.h ./Image/image.h
Ray/rayCone.todo.o: /usr/include/stdio.h /usr/include/libio.h
Ray/rayCone.todo.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayCone.todo.o: Image/lineSegments.h Ray/rayShape.h Ray/rayLight.h
Ray/rayCone.todo.o: Ray/rayGroup.h Ray/rayKey.h ./Util/parameterSamples.h
Ray/rayCone.todo.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/rayCone.todo.o: Ray/rayCone.h
Ray/rayCylinder.o: /usr/include/stdio.h /usr/include/features.h
Ray/rayCylinder.o: /usr/include/stdc-predef.h /usr/include/libio.h
Ray/rayCylinder.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayCylinder.o: /usr/include/stdlib.h /usr/include/alloca.h
Ray/rayCylinder.o: /usr/include/math.h Ray/rayCylinder.h ./Util/geometry.h
Ray/rayCylinder.o: Ray/rayShape.h Ray/rayScene.h ./Image/image.h
Ray/rayCylinder.o: Image/lineSegments.h /usr/include/GL/glut.h
Ray/rayCylinder.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
Ray/rayCylinder.o: /usr/include/GL/glext.h /usr/include/inttypes.h
Ray/rayCylinder.o: /usr/include/stdint.h /usr/include/GL/glu.h Ray/rayLight.h
Ray/rayCylinder.o: Ray/rayGroup.h Ray/rayKey.h ./Util/parameterSamples.h
Ray/rayCylinder.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/rayCylinder.todo.o: /usr/include/math.h /usr/include/features.h
Ray/rayCylinder.todo.o: /usr/include/stdc-predef.h /usr/include/GL/glut.h
Ray/rayCylinder.todo.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
Ray/rayCylinder.todo.o: /usr/include/GL/glext.h /usr/include/inttypes.h
Ray/rayCylinder.todo.o: /usr/include/stdint.h /usr/include/GL/glu.h
Ray/rayCylinder.todo.o: /usr/include/stdlib.h /usr/include/alloca.h
Ray/rayCylinder.todo.o: Ray/rayScene.h ./Util/geometry.h ./Image/image.h
Ray/rayCylinder.todo.o: /usr/include/stdio.h /usr/include/libio.h
Ray/rayCylinder.todo.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayCylinder.todo.o: Image/lineSegments.h Ray/rayShape.h Ray/rayLight.h
Ray/rayCylinder.todo.o: Ray/rayGroup.h Ray/rayKey.h ./Util/parameterSamples.h
Ray/rayCylinder.todo.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/rayCylinder.todo.o: Ray/rayCylinder.h
Ray/rayDirectionalLight.o: /usr/include/stdio.h /usr/include/features.h
Ray/rayDirectionalLight.o: /usr/include/stdc-predef.h /usr/include/libio.h
Ray/rayDirectionalLight.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayDirectionalLight.o: /usr/include/string.h /usr/include/xlocale.h
Ray/rayDirectionalLight.o: /usr/include/math.h ./Util/geometry.h
Ray/rayDirectionalLight.o: Ray/rayDirectionalLight.h Ray/rayLight.h
Ray/rayDirectionalLight.o: Ray/rayShape.h Ray/rayScene.h ./Image/image.h
Ray/rayDirectionalLight.o: Image/lineSegments.h /usr/include/GL/glut.h
Ray/rayDirectionalLight.o: /usr/include/GL/freeglut_std.h
Ray/rayDirectionalLight.o: /usr/include/GL/gl.h /usr/include/GL/glext.h
Ray/rayDirectionalLight.o: /usr/include/inttypes.h /usr/include/stdint.h
Ray/rayDirectionalLight.o: /usr/include/GL/glu.h /usr/include/stdlib.h
Ray/rayDirectionalLight.o: /usr/include/alloca.h Ray/rayGroup.h Ray/rayKey.h
Ray/rayDirectionalLight.o: ./Util/parameterSamples.h
Ray/rayDirectionalLight.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/rayDirectionalLight.todo.o: /usr/include/math.h /usr/include/features.h
Ray/rayDirectionalLight.todo.o: /usr/include/stdc-predef.h
Ray/rayDirectionalLight.todo.o: /usr/include/GL/glut.h
Ray/rayDirectionalLight.todo.o: /usr/include/GL/freeglut_std.h
Ray/rayDirectionalLight.todo.o: /usr/include/GL/gl.h /usr/include/GL/glext.h
Ray/rayDirectionalLight.todo.o: /usr/include/inttypes.h /usr/include/stdint.h
Ray/rayDirectionalLight.todo.o: /usr/include/GL/glu.h /usr/include/stdlib.h
Ray/rayDirectionalLight.todo.o: /usr/include/alloca.h
Ray/rayDirectionalLight.todo.o: Ray/rayDirectionalLight.h Ray/rayLight.h
Ray/rayDirectionalLight.todo.o: Ray/rayShape.h /usr/include/stdio.h
Ray/rayDirectionalLight.todo.o: /usr/include/libio.h /usr/include/_G_config.h
Ray/rayDirectionalLight.todo.o: /usr/include/wchar.h ./Util/geometry.h
Ray/rayDirectionalLight.todo.o: Ray/rayScene.h ./Image/image.h
Ray/rayDirectionalLight.todo.o: Image/lineSegments.h Ray/rayGroup.h
Ray/rayDirectionalLight.todo.o: Ray/rayKey.h ./Util/parameterSamples.h
Ray/rayDirectionalLight.todo.o: ./Util/parameterSamples.todo.inl
Ray/rayDirectionalLight.todo.o: Ray/rayCamera.h
Ray/rayFileInstance.o: /usr/include/stdio.h /usr/include/features.h
Ray/rayFileInstance.o: /usr/include/stdc-predef.h /usr/include/libio.h
Ray/rayFileInstance.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayFileInstance.o: /usr/include/stdlib.h /usr/include/alloca.h
Ray/rayFileInstance.o: Ray/rayFileInstance.h ./Util/geometry.h Ray/rayShape.h
Ray/rayFileInstance.o: Ray/rayScene.h ./Image/image.h Image/lineSegments.h
Ray/rayFileInstance.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
Ray/rayFileInstance.o: /usr/include/GL/gl.h /usr/include/GL/glext.h
Ray/rayFileInstance.o: /usr/include/inttypes.h /usr/include/stdint.h
Ray/rayFileInstance.o: /usr/include/GL/glu.h Ray/rayLight.h Ray/rayGroup.h
Ray/rayFileInstance.o: Ray/rayKey.h ./Util/parameterSamples.h
Ray/rayFileInstance.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/rayGroup.o: /usr/include/stdio.h /usr/include/features.h
Ray/rayGroup.o: /usr/include/stdc-predef.h /usr/include/libio.h
Ray/rayGroup.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayGroup.o: /usr/include/assert.h /usr/include/stdlib.h
Ray/rayGroup.o: /usr/include/alloca.h /usr/include/string.h
Ray/rayGroup.o: /usr/include/xlocale.h Ray/rayGroup.h ./Util/geometry.h
Ray/rayGroup.o: Ray/rayShape.h Ray/rayScene.h ./Image/image.h
Ray/rayGroup.o: Image/lineSegments.h /usr/include/GL/glut.h
Ray/rayGroup.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
Ray/rayGroup.o: /usr/include/GL/glext.h /usr/include/inttypes.h
Ray/rayGroup.o: /usr/include/stdint.h /usr/include/GL/glu.h Ray/rayLight.h
Ray/rayGroup.o: Ray/rayKey.h ./Util/parameterSamples.h
Ray/rayGroup.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/rayGroup.todo.o: /usr/include/stdlib.h /usr/include/features.h
Ray/rayGroup.todo.o: /usr/include/stdc-predef.h /usr/include/alloca.h
Ray/rayGroup.todo.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
Ray/rayGroup.todo.o: /usr/include/GL/gl.h /usr/include/GL/glext.h
Ray/rayGroup.todo.o: /usr/include/inttypes.h /usr/include/stdint.h
Ray/rayGroup.todo.o: /usr/include/GL/glu.h Ray/rayGroup.h ./Util/geometry.h
Ray/rayGroup.todo.o: Ray/rayShape.h /usr/include/stdio.h /usr/include/libio.h
Ray/rayGroup.todo.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayGroup.todo.o: Ray/rayScene.h ./Image/image.h Image/lineSegments.h
Ray/rayGroup.todo.o: Ray/rayLight.h Ray/rayKey.h ./Util/parameterSamples.h
Ray/rayGroup.todo.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/rayKey.o: /usr/include/stdio.h /usr/include/features.h
Ray/rayKey.o: /usr/include/stdc-predef.h /usr/include/libio.h
Ray/rayKey.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayKey.o: /usr/include/string.h /usr/include/xlocale.h ./Util/geometry.h
Ray/rayKey.o: ./Util/cmdLineParser.h Ray/rayGroup.h Ray/rayShape.h
Ray/rayKey.o: Ray/rayScene.h ./Image/image.h Image/lineSegments.h
Ray/rayKey.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
Ray/rayKey.o: /usr/include/GL/gl.h /usr/include/GL/glext.h
Ray/rayKey.o: /usr/include/inttypes.h /usr/include/stdint.h
Ray/rayKey.o: /usr/include/GL/glu.h /usr/include/stdlib.h
Ray/rayKey.o: /usr/include/alloca.h Ray/rayLight.h Ray/rayKey.h
Ray/rayKey.o: ./Util/parameterSamples.h ./Util/parameterSamples.todo.inl
Ray/rayKey.o: Ray/rayCamera.h
Ray/rayPointLight.o: /usr/include/stdio.h /usr/include/features.h
Ray/rayPointLight.o: /usr/include/stdc-predef.h /usr/include/libio.h
Ray/rayPointLight.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayPointLight.o: /usr/include/string.h /usr/include/xlocale.h
Ray/rayPointLight.o: /usr/include/math.h ./Util/geometry.h
Ray/rayPointLight.o: Ray/rayPointLight.h Ray/rayLight.h Ray/rayShape.h
Ray/rayPointLight.o: Ray/rayScene.h ./Image/image.h Image/lineSegments.h
Ray/rayPointLight.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
Ray/rayPointLight.o: /usr/include/GL/gl.h /usr/include/GL/glext.h
Ray/rayPointLight.o: /usr/include/inttypes.h /usr/include/stdint.h
Ray/rayPointLight.o: /usr/include/GL/glu.h /usr/include/stdlib.h
Ray/rayPointLight.o: /usr/include/alloca.h Ray/rayGroup.h Ray/rayKey.h
Ray/rayPointLight.o: ./Util/parameterSamples.h
Ray/rayPointLight.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/rayPointLight.todo.o: /usr/include/math.h /usr/include/features.h
Ray/rayPointLight.todo.o: /usr/include/stdc-predef.h /usr/include/GL/glut.h
Ray/rayPointLight.todo.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
Ray/rayPointLight.todo.o: /usr/include/GL/glext.h /usr/include/inttypes.h
Ray/rayPointLight.todo.o: /usr/include/stdint.h /usr/include/GL/glu.h
Ray/rayPointLight.todo.o: /usr/include/stdlib.h /usr/include/alloca.h
Ray/rayPointLight.todo.o: Ray/rayPointLight.h Ray/rayLight.h Ray/rayShape.h
Ray/rayPointLight.todo.o: /usr/include/stdio.h /usr/include/libio.h
Ray/rayPointLight.todo.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayPointLight.todo.o: ./Util/geometry.h Ray/rayScene.h ./Image/image.h
Ray/rayPointLight.todo.o: Image/lineSegments.h Ray/rayGroup.h Ray/rayKey.h
Ray/rayPointLight.todo.o: ./Util/parameterSamples.h
Ray/rayPointLight.todo.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/rayScene.o: /usr/include/stdlib.h /usr/include/features.h
Ray/rayScene.o: /usr/include/stdc-predef.h /usr/include/alloca.h
Ray/rayScene.o: /usr/include/stdio.h /usr/include/libio.h
Ray/rayScene.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayScene.o: /usr/include/string.h /usr/include/xlocale.h
Ray/rayScene.o: /usr/include/math.h ./Image/bmp.h Image/image.h
Ray/rayScene.o: Image/lineSegments.h Ray/rayScene.h ./Util/geometry.h
Ray/rayScene.o: ./Image/image.h /usr/include/GL/glut.h
Ray/rayScene.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
Ray/rayScene.o: /usr/include/GL/glext.h /usr/include/inttypes.h
Ray/rayScene.o: /usr/include/stdint.h /usr/include/GL/glu.h Ray/rayShape.h
Ray/rayScene.o: Ray/rayLight.h Ray/rayGroup.h Ray/rayKey.h
Ray/rayScene.o: ./Util/parameterSamples.h ./Util/parameterSamples.todo.inl
Ray/rayScene.o: Ray/rayCamera.h Ray/rayPointLight.h Ray/rayDirectionalLight.h
Ray/rayScene.o: Ray/raySpotLight.h Ray/rayFileInstance.h Ray/raySphere.h
Ray/rayScene.o: Ray/rayBox.h Ray/rayCone.h Ray/rayCylinder.h
Ray/rayScene.o: Ray/rayTriangle.h
Ray/rayScene.todo.o: Ray/rayScene.h ./Util/geometry.h ./Image/image.h
Ray/rayScene.todo.o: /usr/include/stdio.h /usr/include/features.h
Ray/rayScene.todo.o: /usr/include/stdc-predef.h /usr/include/libio.h
Ray/rayScene.todo.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayScene.todo.o: Image/lineSegments.h /usr/include/GL/glut.h
Ray/rayScene.todo.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
Ray/rayScene.todo.o: /usr/include/GL/glext.h /usr/include/inttypes.h
Ray/rayScene.todo.o: /usr/include/stdint.h /usr/include/GL/glu.h
Ray/rayScene.todo.o: /usr/include/stdlib.h /usr/include/alloca.h
Ray/rayScene.todo.o: Ray/rayShape.h Ray/rayLight.h Ray/rayGroup.h
Ray/rayScene.todo.o: Ray/rayKey.h ./Util/parameterSamples.h
Ray/rayScene.todo.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/rayScene.todo.o: /usr/include/math.h
Ray/raySphere.o: /usr/include/stdio.h /usr/include/features.h
Ray/raySphere.o: /usr/include/stdc-predef.h /usr/include/libio.h
Ray/raySphere.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/raySphere.o: /usr/include/stdlib.h /usr/include/alloca.h
Ray/raySphere.o: /usr/include/math.h Ray/raySphere.h ./Util/geometry.h
Ray/raySphere.o: Ray/rayShape.h Ray/rayScene.h ./Image/image.h
Ray/raySphere.o: Image/lineSegments.h /usr/include/GL/glut.h
Ray/raySphere.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
Ray/raySphere.o: /usr/include/GL/glext.h /usr/include/inttypes.h
Ray/raySphere.o: /usr/include/stdint.h /usr/include/GL/glu.h Ray/rayLight.h
Ray/raySphere.o: Ray/rayGroup.h Ray/rayKey.h ./Util/parameterSamples.h
Ray/raySphere.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/raySphere.todo.o: /usr/include/math.h /usr/include/features.h
Ray/raySphere.todo.o: /usr/include/stdc-predef.h /usr/include/GL/glut.h
Ray/raySphere.todo.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
Ray/raySphere.todo.o: /usr/include/GL/glext.h /usr/include/inttypes.h
Ray/raySphere.todo.o: /usr/include/stdint.h /usr/include/GL/glu.h
Ray/raySphere.todo.o: /usr/include/stdlib.h /usr/include/alloca.h
Ray/raySphere.todo.o: Ray/rayScene.h ./Util/geometry.h ./Image/image.h
Ray/raySphere.todo.o: /usr/include/stdio.h /usr/include/libio.h
Ray/raySphere.todo.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/raySphere.todo.o: Image/lineSegments.h Ray/rayShape.h Ray/rayLight.h
Ray/raySphere.todo.o: Ray/rayGroup.h Ray/rayKey.h ./Util/parameterSamples.h
Ray/raySphere.todo.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/raySphere.todo.o: Ray/raySphere.h
Ray/raySpotLight.o: /usr/include/stdio.h /usr/include/features.h
Ray/raySpotLight.o: /usr/include/stdc-predef.h /usr/include/libio.h
Ray/raySpotLight.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/raySpotLight.o: /usr/include/string.h /usr/include/xlocale.h
Ray/raySpotLight.o: /usr/include/math.h ./Util/geometry.h Ray/raySpotLight.h
Ray/raySpotLight.o: Ray/rayLight.h Ray/rayShape.h Ray/rayScene.h
Ray/raySpotLight.o: ./Image/image.h Image/lineSegments.h
Ray/raySpotLight.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
Ray/raySpotLight.o: /usr/include/GL/gl.h /usr/include/GL/glext.h
Ray/raySpotLight.o: /usr/include/inttypes.h /usr/include/stdint.h
Ray/raySpotLight.o: /usr/include/GL/glu.h /usr/include/stdlib.h
Ray/raySpotLight.o: /usr/include/alloca.h Ray/rayGroup.h Ray/rayKey.h
Ray/raySpotLight.o: ./Util/parameterSamples.h
Ray/raySpotLight.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/raySpotLight.todo.o: /usr/include/math.h /usr/include/features.h
Ray/raySpotLight.todo.o: /usr/include/stdc-predef.h /usr/include/GL/glut.h
Ray/raySpotLight.todo.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
Ray/raySpotLight.todo.o: /usr/include/GL/glext.h /usr/include/inttypes.h
Ray/raySpotLight.todo.o: /usr/include/stdint.h /usr/include/GL/glu.h
Ray/raySpotLight.todo.o: /usr/include/stdlib.h /usr/include/alloca.h
Ray/raySpotLight.todo.o: Ray/rayScene.h ./Util/geometry.h ./Image/image.h
Ray/raySpotLight.todo.o: /usr/include/stdio.h /usr/include/libio.h
Ray/raySpotLight.todo.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/raySpotLight.todo.o: Image/lineSegments.h Ray/rayShape.h Ray/rayLight.h
Ray/raySpotLight.todo.o: Ray/rayGroup.h Ray/rayKey.h
Ray/raySpotLight.todo.o: ./Util/parameterSamples.h
Ray/raySpotLight.todo.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/raySpotLight.todo.o: Ray/raySpotLight.h
Ray/rayTriangle.o: /usr/include/stdio.h /usr/include/features.h
Ray/rayTriangle.o: /usr/include/stdc-predef.h /usr/include/libio.h
Ray/rayTriangle.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayTriangle.o: /usr/include/stdlib.h /usr/include/alloca.h
Ray/rayTriangle.o: /usr/include/math.h Ray/rayTriangle.h ./Util/geometry.h
Ray/rayTriangle.o: Ray/rayShape.h Ray/rayScene.h ./Image/image.h
Ray/rayTriangle.o: Image/lineSegments.h /usr/include/GL/glut.h
Ray/rayTriangle.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
Ray/rayTriangle.o: /usr/include/GL/glext.h /usr/include/inttypes.h
Ray/rayTriangle.o: /usr/include/stdint.h /usr/include/GL/glu.h Ray/rayLight.h
Ray/rayTriangle.o: Ray/rayGroup.h Ray/rayKey.h ./Util/parameterSamples.h
Ray/rayTriangle.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/rayTriangle.todo.o: /usr/include/stdio.h /usr/include/features.h
Ray/rayTriangle.todo.o: /usr/include/stdc-predef.h /usr/include/libio.h
Ray/rayTriangle.todo.o: /usr/include/_G_config.h /usr/include/wchar.h
Ray/rayTriangle.todo.o: /usr/include/stdlib.h /usr/include/alloca.h
Ray/rayTriangle.todo.o: /usr/include/math.h Ray/rayTriangle.h
Ray/rayTriangle.todo.o: ./Util/geometry.h Ray/rayShape.h Ray/rayScene.h
Ray/rayTriangle.todo.o: ./Image/image.h Image/lineSegments.h
Ray/rayTriangle.todo.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
Ray/rayTriangle.todo.o: /usr/include/GL/gl.h /usr/include/GL/glext.h
Ray/rayTriangle.todo.o: /usr/include/inttypes.h /usr/include/stdint.h
Ray/rayTriangle.todo.o: /usr/include/GL/glu.h Ray/rayLight.h Ray/rayGroup.h
Ray/rayTriangle.todo.o: Ray/rayKey.h ./Util/parameterSamples.h
Ray/rayTriangle.todo.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h
Ray/rayWindow.o: /usr/include/string.h /usr/include/features.h
Ray/rayWindow.o: /usr/include/stdc-predef.h /usr/include/xlocale.h
Ray/rayWindow.o: ./Util/time.h Ray/rayWindow.h ./Ray/mouse.h ./Ray/rayScene.h
Ray/rayWindow.o: ./Util/geometry.h ./Image/image.h /usr/include/stdio.h
Ray/rayWindow.o: /usr/include/libio.h /usr/include/_G_config.h
Ray/rayWindow.o: /usr/include/wchar.h Image/lineSegments.h
Ray/rayWindow.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
Ray/rayWindow.o: /usr/include/GL/gl.h /usr/include/GL/glext.h
Ray/rayWindow.o: /usr/include/inttypes.h /usr/include/stdint.h
Ray/rayWindow.o: /usr/include/GL/glu.h /usr/include/stdlib.h
Ray/rayWindow.o: /usr/include/alloca.h Ray/rayShape.h Ray/rayLight.h
Ray/rayWindow.o: Ray/rayGroup.h Ray/rayScene.h Ray/rayKey.h
Ray/rayWindow.o: ./Util/parameterSamples.h ./Util/parameterSamples.todo.inl
Ray/rayWindow.o: Ray/rayCamera.h
main.o: /usr/include/stdio.h /usr/include/features.h
main.o: /usr/include/stdc-predef.h /usr/include/libio.h
main.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/stdlib.h
main.o: /usr/include/alloca.h ./Util/cmdLineParser.h /usr/include/string.h
main.o: /usr/include/xlocale.h ./Ray/rayScene.h ./Util/geometry.h
main.o: ./Image/image.h Image/lineSegments.h /usr/include/GL/glut.h
main.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
main.o: /usr/include/GL/glext.h /usr/include/inttypes.h /usr/include/stdint.h
main.o: /usr/include/GL/glu.h Ray/rayShape.h Ray/rayLight.h Ray/rayGroup.h
main.o: Ray/rayScene.h Ray/rayKey.h ./Util/parameterSamples.h
main.o: ./Util/parameterSamples.todo.inl Ray/rayCamera.h ./Ray/rayWindow.h
main.o: ./Ray/mouse.h ./Util/time.h
