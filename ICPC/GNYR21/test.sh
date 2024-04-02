clang++ -std=c++17 -O2 -o main $1.cpp
for f in ./acmgnyr.org/year2021/judge-data/$1*/judge/*.in; do
    # filename=$(basename -- "$f")
    extension="${f##*.}"
    test_case="${f%.*}"
    test_case+=".ans"
    echo $test_case
    time ./main < $f > out.txt
    diff out.txt $test_case || break
done
