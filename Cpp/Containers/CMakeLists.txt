project("Containers")

single_executable(src/iterators.cpp)
single_executable(src/algorithms.cpp)
single_executable(src/deque.cpp)

single_executable(src/associative/map.cpp)
single_executable(src/associative/unordered_map.cpp)
single_executable(src/associative/set.cpp)
single_executable(src/associative/unordered_set.cpp)

single_executable(src/associative/multi/multimap.cpp)
single_executable(src/associative/multi/unordered_multimap.cpp)
single_executable(src/associative/multi/multiset.cpp)
single_executable(src/associative/multi/unordered_multiset.cpp)