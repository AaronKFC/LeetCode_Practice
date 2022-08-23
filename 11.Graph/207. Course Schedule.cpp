/*
    Courses & prerequisites, return true if can finish all courses
    Ex. numCourses = 2, prerequisites = [[1,0]] -> true

    All courses can be completed if there's no cycle (visit already visited)

    Time: O(V + E)
    Space: O(V + E)
*/

// Solution1 (My implementation)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i=0; i<prerequisites.size(); i++) {
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        // 寫法一：
        for (int course=0; course<numCourses; course++) {
            if (!dfs(course)) {
                return false;
            }
        }
        
        // 寫法二： (My implementation) faster
        // for (int i=0; i<prerequisites.size(); i++) {
        //     if (!dfs(prerequisites[i][0])) {
        //         return false;
        //     }
        // }
        
        return true;
    }
private:
    unordered_map<int, vector<int>> m;
    unordered_set<int> visited;
    bool dfs(int course) {
        if (visited.find(course) != visited.end()) {
            return false;
        }
        if (m[course].empty()) {
            return true;
        }
        
        visited.insert(course);
        for (int i=0; i<m[course].size(); i++) {
            if (!dfs(m[course][i])) {
                return false;
            }
        }
        
        m[course].clear();
        visited.erase(course);
        return true;
    }
};


// Solution2 (NeetCode)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // map each course to prereq list
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < prerequisites.size(); i++) {
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // all courses along current DFS path
        unordered_set<int> visited;
        
        for (int course = 0; course < numCourses; course++) {
            if (!dfs(course, m, visited)) {
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(int course, unordered_map<int, vector<int>>& m, unordered_set<int>& visited) {
        if (visited.find(course) != visited.end()) {
            return false;
        }
        if (m[course].empty()) {
            return true;
        }
        visited.insert(course);
        for (int i = 0; i < m[course].size(); i++) {
            int nextCourse = m[course][i];
            if (!dfs(nextCourse, m, visited)) {
                return false;
            }
        }
        m[course].clear();
        visited.erase(course);
        return true;
    }
};

