TMPFILE="/tmp/file.bc"
LLVM="/opt/llvm/"

 echo "This is the VCC command line tool. Usage vcc.sh source.c dst.v"

UNT="-units_mul=4 -units_div=1 -units_memport=1 -units_shl=1"
DLY="-delay_mul=5 -delay_div=5 -delay_memport=1 -delay_shl=5"
WRE="-inline_op_to_wire=4 "
DBG="-include_size=1 -include_clocks=1 -include_freq=1"
MEM="-mem_wordsize=32 -membus_size=16"
SYNFLAGS="$UNT $DLY $WRE $DBG $MEM"

#OPTFLAGS="-unroll-threshold=20 -inline-threshold=4096 -inline -loopsimplify -loop-rotate -loop-unroll -std-compile-opts -indvars -simplifycfg" #-parallel_balance #-reduce_bitwidth -detect_arrays"
OPTFLAGS="-unroll-threshold=512 -inline-threshold=4096 -inline -loopsimplify -loop-rotate -std-compile-opts -loop-unroll -indvars -simplifycfg -parallel_balance" #-reduce_bitwidth -detect_arrays"
MYFLAGS="-parallel_balance -reduce_bitwidth " #-detect_arrays"
 
rm -f $TMPFILE
rm -f /tmp/dis.txt /tmp/dis1.txt /tmp/dis2.txt /tmp/dis3.txt /tmp/dis4.txt

$LLVM/bin/g++ -emit-llvm -c $1 -o $TMPFILE
$LLVM/bin/llvm-dis $TMPFILE -o /tmp/dis1.txt
$LLVM/bin/opt -load=$LLVM/lib/LLVMPrepareSynthesis.so $OPTFLAGS $MEM $TMPFILE -o $TMPFILE -f
$LLVM/bin/llvm-dis $TMPFILE -o /tmp/dis2.txt
$LLVM/bin/opt -load=$LLVM/lib/LLVMPrepareSynthesis.so -dce -ms -adce $TMPFILE -o $TMPFILE -f
$LLVM/bin/llvm-dis $TMPFILE -o /tmp/dis3.txt
$LLVM/bin/opt -load=$LLVM/lib/LLVMPrepareSynthesis.so -dse -std-compile-opts $MYFLAGS $TMPFILE -o $TMPFILE -f
$LLVM/bin/llvm-dis $TMPFILE -o /tmp/dis4.txt
$LLVM/bin/llc -load=$LLVM/lib/LLVMSynthesis.so -march=v $SYNFLAGS $TMPFILE -f -o=$2

