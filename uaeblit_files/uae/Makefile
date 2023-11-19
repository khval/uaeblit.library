
obj_dir = objs

CFLAGS = -Iinc/

objs += $(obj_dir)/blitfunc.o
objs += $(obj_dir)/blitops.o
objs += $(obj_dir)/blittable.o
objs += $(obj_dir)/blitter.o
objs += $(obj_dir)/custom.o
objs += $(obj_dir)/dummy.o

# objs += $(obj_dir)/genblitter.o
# objs += $(obj_dir)/gengenblitter.o

all: $(objs) libuaeblit.a

clean:
	delete #?.a #?.o objs/#?.o

$(obj_dir)/%.o:	%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $(OUTPUT_OPTION) $<

libuaeblit.a: $(objs)
	ar r libuaeblit.a $(objs)