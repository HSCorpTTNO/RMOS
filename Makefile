all:
	# objcopy -I binary -O elf64-x86-64 kernel/Omega/zap-light16.psf kernel/font.o
	# objcopy -I binary -O elf64-x86-64 -B i386 kernel/Omega/zap-light16.psf font.o
	cd kernel/; rm -rf limine 2> /dev/null; make clean; bash buildall.sh
	cd kernel/; bash build.sh; mv RMOS.iso ../
	@ rm $$(find ./ -type f -name "*.d")
	@ rm $$(find ./ -type f -name "*.o")

deps:
	git clone https://github.com/limine-bootloader/limine.git --branch=v2.0-branch-binary --depth=1 kernel/limine

reset:
	cd kernel/; make clean; rm -rf limine
	@ rm $$(find ./ -type f -name "*.d")
	@ rm $$(find ./ -type f -name "*.o")

run:
	qemu-system-x86_64 -cdrom RMOS.iso -monitor stdio -d int -no-reboot -D logfile.txt -M smm=off 

# DO NOT USE THIS WITHOUT KNOWING WHAT YOU ARE DOING!
burn_danger:
	dd if=RMOS.iso of=/dev/sdb status=progress
