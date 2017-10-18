/**************************************************************************
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence
and not a substring.
key: brute force, slide window, harsh table
**************************************************************************/
int lengthOfLongestSubstring(char* s) {
	int ascii_index[256];
	int i = 0, j = 0;
	int len_max = 0;
	for (i = 0; i < 256; i++)
	{
		ascii_index[i] = -1;
	}
	i = 0;
	while (*s != '\0')
	{
		//len_max++;
		if (ascii_index[*s] != -1)
		{
			i = i > ascii_index[*s] ? i : ascii_index[*s] + 1;
		}
		len_max = len_max > (j - i + 1) ? len_max : (j - i + 1);
		ascii_index[*s] = j;
		j++;
		s++;
	}
	return len_max;

}
