LDFLAGS= -lm -limago -lpng -ljpeg

default: test-hist
all: test-hist test-lhist test-stif test-lstif test-threshold al-blur al-thresh al-enhance lms-img

test-hist: test-hist.o histogram.o bbox.o img.o
	$(CC) test-hist.o histogram.o bbox.o img.o $(LDFLAGS) -o $@

test-lhist: test-lhist.o histogram.o bbox.o img.o
	$(CC) test-lhist.o histogram.o bbox.o img.o $(LDFLAGS) -o $@

test-stif: test-stif.o stif.o histogram.o bbox.o img.o
	$(CC) test-stif.o stif.o histogram.o bbox.o img.o $(LDFLAGS) -o $@

test-lstif: test-lstif.o stif.o histogram.o bbox.o img.o
	$(CC) test-lstif.o stif.o histogram.o bbox.o img.o $(LDFLAGS) -o $@

test-threshold: test-threshold.o threshold.o stif.o histogram.o bbox.o img.o
	$(CC) test-threshold.o threshold.o stif.o histogram.o bbox.o img.o $(LDFLAGS) -o $@

al-blur: al-blur.o threshold.o stif.o histogram.o bbox.o img.o
	$(CC) al-blur.o threshold.o stif.o histogram.o bbox.o img.o $(LDFLAGS) -o $@

al-thresh: al-thresh.o threshold.o stif.o histogram.o bbox.o img.o
	$(CC) al-thresh.o threshold.o stif.o histogram.o bbox.o img.o $(LDFLAGS) -o $@

al-enhance: al-enhance.o threshold.o stif.o histogram.o bbox.o img.o
	$(CC) al-enhance.o threshold.o stif.o histogram.o bbox.o img.o $(LDFLAGS) -o $@

lms-img: lms-img.o threshold.o stif.o histogram.o bbox.o img.o
	$(CC) lms-img.o threshold.o stif.o histogram.o bbox.o img.o $(LDFLAGS) -o $@


test-hist.o: test-hist.c histogram.h
test-lhist.o: test-lhist.c histogram.h
test-stif.o: test-stif.c histogram.h
test-lstif.o: test-lstif.c histogram.h
test-threshold.o: test-threshold.c histogram.h
al-blur.o: al-blur.c histogram.h
al-thresh.o: al-thresh.c histogram.h
al-enhance.o: al-enhance.c histogram.h
lms-img.o: lms-img.c histogram.h
bbox.o: bbox.c bbox.h
img.o: img.c img.h

stif.o: stif.c stif.h histogram.h
histogram.o: histogram.c histogram.h bbox.h
threshold.o: threshold.c threshold.h histogram.h stif.h

cleanall : clean
	rm -f test-hist test-lhist test-stif test-lstif test-threshold al-blur al-thresh al-enhance lms-img

clean :  
	rm -f test-hist.o test-lhist.o test-stif.o test-lstif.o test-threshold.o stif.o histogram.o threshold.o bbox.o img.o al-blur.o al-thresh.o al-enhance.o lms-img.o






