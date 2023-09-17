/**
 * 前缀树：
 * 前缀树又称字典树，是一颗有根树，其中每个节点包含以下字段：
 * - 指向子结点的指针数组children，指针数组，也就是说数组中每个元素都是指向子结点的指针
 *  - 对于实现单词查找的前缀树而言，指针数组的长度为26，也就是说每个节点最多有26个子结点
 *  - 可以用数组children[26]来表示26个字母
 * - bool字段，表示该节点是否为字符串的结尾
 */
#include <vector>
#include <string>
using std::vector, std::string;


class Trie
{
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (auto&& ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) return nullptr;
            node = node->children[ch];
        }

        return node;    // 返回整个前缀的最后一个节点
    }

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;  // 从此刻的节点node开始
        for (auto&& ch : word) {    // 针对word中的每一个字母建前缀树
            ch -= 'a';      // ch转换为了对应的index
            if (!node->children[ch]) {
                node->children[ch] = new Trie();    // 一个新的节点
            }

            node = node->children[ch];
        }
        node->isEnd = true; // 最后一个节点，确认是结尾
    }

    bool search(string word) {
        Trie* node = searchPrefix(word);
        return node && node->isEnd;
    }

    bool startsWith(string prefix) {
        return searchPrefix(prefix);
    }

};
