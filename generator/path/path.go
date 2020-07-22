package path

import (
	"regexp"

	"github.com/pkg/errors"
)

// https://leetcode.com/contest/biweekly-contest-20/problems/sort-integers-by-the-number-of-1-bits/ -> sort-integers-by-the-number-of-1-bits
func GetProblemIdentifiers(URL string) (string, error) {
	reg := regexp.MustCompile(`/problems\/([^\/]+)`)
	res := reg.FindStringSubmatch(URL)

	if len(res) != 2 {
		return "", errors.New("URL invalid")
	}

	return res[1], nil
}

func GetPath(URL string) (string, error) {
	problem, err := GetProblemIdentifiers(URL)

	if err != nil {
		return "", errors.WithStack(err)
	}

	return "./problems/" + problem, nil
}
