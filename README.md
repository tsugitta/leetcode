LeetCode contest challenge.

https://leetcode.com/tsugitta

## Structure

```
└── contests
    └── contest_name
        └── problem_id
            └── main.cpp
```

- main.cpp is the code to submit

## Generator

in the root dir, running

```
$ go run generator/main.go https://leetcode.com/contest/contest-name/problems/problem-name/
```

creates a dir & file for the problem with the template file.
