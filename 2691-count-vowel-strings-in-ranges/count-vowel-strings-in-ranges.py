class Solution(object):
    def vowelStrings(self, words, queries):
        vowels = ['a', 'e', 'i', 'o', 'u']
        pre = [0] * (len(words) + 1)
        for i in range(0, len(words)):
            temp = words[i]
            if temp[0] in vowels and temp[-1] in vowels:
                pre[i + 1] = pre[i] + 1
            else:
                pre[i + 1] = pre[i]

        answer = []
        for i, j in queries:
            answer.append(pre[j + 1] - pre[i])

        return answer