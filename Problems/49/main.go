package main

func main() {

}

// Hashmap Implementation (Golang array is compariable)
// But I am still trying to find the implementation of golang array hasher
// Make sure it provide O(1) implementation
func groupAnagrams(strs []string) [][]string {
	// O(N), where N equal total string length
	// Space, O(len(strs)), map structure

	anagramMap := make(map[[26]int][]string)

	for _, s := range strs {
		var chars [26]int

		for _, r := range s {
			chars[r-'a']++
		}
		anagramMap[chars] = append(anagramMap[chars], s)
	}

	// Generate Result
	result := make([][]string, 0)
	for _, v := range anagramMap {
		result = append(result, v)
	}

	return result
}
