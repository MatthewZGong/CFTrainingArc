clang++ -std=c++17 -O2 -o main $1.cpp
for f in ./acmgnyr.org/*/*/$1*/*/*.in; do
    # filename=$(basename -- "$f")
    extension="${f##*.}"
    test_case="${f%.*}"
    test_case+=".ans"
    echo $test_case
    time ./main < $f > out.txt
    diff -w out.txt $test_case || break
done
