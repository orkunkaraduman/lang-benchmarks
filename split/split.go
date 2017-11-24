package main

import (
	"fmt"
	"strings"
	"os"
	"bufio"
)

func main() {
	f, err := os.Open("lipsum.txt")
	if err != nil {
		panic(err)
	}

	for i := 0; i < 1000000; i++ {
		f.Seek(0, 0)
		sc := bufio.NewScanner(f)
		var fields []string
		for sc.Scan() {
			line := sc.Text()
			fields = strings.Split(line, " ")
		}
		if i%1000 == 0 {
			fmt.Printf("%d %s\n", i, fields[i % len(fields)])
		}
	}

	f.Close()
}
