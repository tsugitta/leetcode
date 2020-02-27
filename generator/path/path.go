package path

import (
	"regexp"

	"github.com/pkg/errors"
)

// https://leetcode.com/contest/biweekly-contest-20/problems/sort-integers-by-the-number-of-1-bits/ -> (biweekly-contest-20, sort-integers-by-the-number-of-1-bits)
func GetProblemIdentifiers(URL string) (string, string, error) {
	reg := regexp.MustCompile(`contest\/(.+)\/problems\/(.+)`)
	res := reg.FindStringSubmatch(URL)

	if len(res) != 3 {
		return "", "", errors.New("URL invalid")
	}

	return res[1], res[2], nil
}

func GetPath(URL string) (string, error) {
	contest, problem, err := GetProblemIdentifiers(URL)

	if err != nil {
		return "", errors.WithStack(err)
	}

	return "./contests/" + contest + "/" + problem, nil
}
