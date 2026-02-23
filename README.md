This is small toolchain to build from *.c binaries in native Plan9 format (a.out). 
Project is rebuilded version of [9-cc](https://github.com/0intro/9-cc) project. 
Highly cutted and minimal version for now - Linux/amd64 only. 
Reworked only compiler, linker, assembler, archiver, necessary libs.


Install:
```bash
git clone ...
cd 9ftch
./configure
mk install
```

Test:
```bash
. ./env
ROOT=$(pwd)
cd /tmp

cat > f.c <<'EOF'
int f(void){ return 42; }
EOF

cat > usef.c <<'EOF'
extern int f(void);
extern int print(char*, ...);
extern void exits(char*);

void
main(void)
{
  print("f()=%d\n", f());
  exits(0);
}
EOF

6c f.c
6c usef.c

rm -f libf.a
ar r libf.a f.6

6l -o usef.out usef.6 libf.a $ROOT/9root/amd64/lib/libc.a
```
Then move `usef.out` to native Plan9/9Front system and try to run it there.
