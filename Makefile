all: libtexteditor.a

ctexteditor.o: ctexteditor.h
TextEditor.o: TextEditor.h

libtexteditor.a: TextEditor.o ctexteditor.o
	$(AR) rcUu $@ $+
	ranlib $@

clean:
	rm -f TextEditor.o ctexteditor.o libtexteditor.a

.PHONY: all clean
