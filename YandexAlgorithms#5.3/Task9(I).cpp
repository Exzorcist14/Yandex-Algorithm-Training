#include <bits/stdc++.h>

using namespace std;

bool isInformationAboutMatch(string& line) {
    return line[0] == '\"';
}

void readTeamsAndScoreInformation(string& team1, string& team2, int& score1, int& score2, string& line) {

    bool foundTeam1 = false;
    bool foundTeam2 = false;

    string temp;
    int i = 0;

    while (!foundTeam1) {
        temp += line[i];

        if (line[i] == '\"' && line[i + 1] == ' ') {
            team1 = temp;
            foundTeam1 = true;
            temp = "";
        }

        i++;
    }
    i += 3;

    while (!foundTeam2) {
        temp += line[i];

        if (line[i] == '\"' && line[i + 1] == ' ') {
            team2 = temp;
            foundTeam2 = true;
            temp = "";
        }

        i++;
    }
    i++;

    while (line[i] != ':') {
        temp += line[i];
        i++;
    }
    i++;
    score1 = stoi(temp);

    temp = "";
    while (i != line.size()) {
        temp += line[i];
        i++;
    }
    score2 = stoi(temp);
}

void readGoalInformation(string& footballer, int& minute, ifstream& fin, string& line) {

    getline(fin, line);

    footballer = "";

    int i = 0;
    while (int(line[i + 1]) < 48 || int(line[i + 1] > 57)) {
        footballer += line[i];
        i++;
    }
    i += 1;

    string temp;
    while (line[i] != '\'') {
        temp += line[i];
        i++;
    }

    minute = stoi(temp) - 1;
}

void bringGoalsInfoToPrefixSums(const unordered_map<string, vector<int>>& scorersWithGoalsAndMinutes,
                                unordered_map<string, int[90]>& footballerGoals) {

    for (auto& scorer : scorersWithGoalsAndMinutes) {

        for (auto& goalMinute : scorer.second) {
            footballerGoals[scorer.first][goalMinute]++;

            for (int i = goalMinute + 1; i < 90; i++) {
                footballerGoals[scorer.first][i]++;
            }
        }
    }
}

int determineRequestType(string& line) {
    if (line[0] == 'T' && line[12] == 'f') {
        return 1;
    } else if (line[0] == 'M' && line[20] == 'f') {
        return 2;
    } else if (line[0] == 'T' && line[12] == 'b') {
        return 3;
    } else if (line[0] == 'M' && line[20] == 'b') {
        return 4;
    } else if (line[0] == 'G' && line[9] == 'm') {
        return 5;
    } else if (line[0] == 'G' && line[9] == 'f') {
        return 6;
    } else if (line[0] == 'G' && line[9] == 'l') {
        return 7;
    } else if (line[0] == 'S' && line[15] == '\"') {
        return 8;
    } else {
        return 9;
    }
}

void processRequestType1(string& line, unordered_map<string, int[3]>& teamsTable) {

    string team;

    for (int i = 16; i < line.size(); i++) {
        team += line[i];
    }

    cout << teamsTable[team][0] << "\n";
}

void processRequestType2(string& line, unordered_map<string, int[3]>& teamsTable) {

    string team;

    for (int i = 24; i < line.size(); i++) {
        team += line[i];
    }

    cout << setprecision(14)
    << double(teamsTable[team][0]) / double(teamsTable[team][1])
    << "\n";
}

void processRequestType3(string& line, unordered_map<string, int[90]>& footballerGoals) {

    string footballer;

    for (int i = 15; i < line.size(); i++) {
        footballer += line[i];
    }

    cout << footballerGoals[footballer][89] << "\n";
}

void processRequestType4(string& line, unordered_map<string, int[3]>& teamsTable,
                         unordered_map<string, string>& footballerTeams,
                         unordered_map<string, int[90]>& footballerGoals) {

    string footballer;

    for (int i = 23; i < line.size(); i++) {
        footballer += line[i];
    }

    cout << setprecision(14)
    << double(footballerGoals[footballer][89]) / double(teamsTable[footballerTeams[footballer]][1])
    << "\n";
}

void processRequestType5(string& line, unordered_map<string, int[90]>& footballerGoals) {

    int minute;
    string footballer;

    string temp;

    int i = 16;
    while (line[i] != ' ') {
        temp += line[i];
        i++;
    }
    i += 4;

    minute = stoi(temp) - 1;
    temp = "";

    while (i != line.size()) {
        temp += line[i];
        i++;
    }

    footballer = temp;

    if (minute != 0) {
        cout << footballerGoals[footballer][minute] - footballerGoals[footballer][minute - 1] << "\n";
    } else {
        cout << footballerGoals[footballer][minute] << "\n";
    }
}

void processRequestType6(string& line, unordered_map<string, int[90]>& footballerGoals) {

    int minute;
    string footballer;

    string temp;

    int i = 15;
    while (line[i] != ' ') {
        temp += line[i];
        i++;
    }
    i += 12;

    minute = stoi(temp) - 1;
    temp = "";

    while (i != line.size()) {
        temp += line[i];
        i++;
    }

    footballer = temp;

    cout << footballerGoals[footballer][minute] << "\n";
}

void processRequestType7(string& line, unordered_map<string, int[90]>& footballerGoals) {

    int minute;
    string footballer;

    string temp;

    int i = 14;
    while (line[i] != ' ') {
        temp += line[i];
        i++;
    }
    i += 12;

    minute = stoi(temp);
    temp = "";

    while (i != line.size()) {
        temp += line[i];
        i++;
    }

    footballer = temp;

    cout << footballerGoals[footballer][89] - footballerGoals[footballer][89 - minute] << "\n";
}

void processRequestType8(string& line, unordered_map<string, int[3]>& teamsTable) {

    string team;

    for (int i = 15; i < line.size(); i++) {
        team += line[i];
    }

    cout << teamsTable[team][2] << "\n";
}

void processRequestType9(string& line, unordered_map<string, int>& footbllerOpens) {

    string footballer;

    for (int i = 15; i < line.size(); i++) {
        footballer += line[i];
    }

    cout << footbllerOpens[footballer] << "\n";
}

void solve() {
    unordered_map<string, int[3]> teamsTable;
    unordered_map<string, string> footballerTeams;
    unordered_map<string, int[90]> footballerGoals;
    unordered_map<string, int> footballerOpens;

    string team1;
    string team2;
    int score1;
    int score2;

    string footballer;
    int minute;
    unordered_map<string, vector<int>> scorersWithGoalsAndMinutes;
    pair<string, int> openerTeam1;
    pair<string, int> openerTeam2;

    int requestType;

    ifstream fin("input.txt");
    string line;
    while (getline(fin, line)) {

        if (isInformationAboutMatch(line)) {

            openerTeam1.second = 91;
            openerTeam2.second = 91;

            readTeamsAndScoreInformation(team1, team2, score1, score2, line);
            teamsTable[team1][0] += score1;
            teamsTable[team1][1] += 1;
            teamsTable[team2][0] += score2;
            teamsTable[team2][1] += 1;

            for (int i = 0; i < score1; i++) {

                readGoalInformation(footballer, minute, fin, line);
                scorersWithGoalsAndMinutes[footballer].push_back(minute);

                if (!footballerTeams.contains(footballer)) {
                    footballerTeams[footballer] = team1;
                }

                if (i == 0) {
                    openerTeam1 = {footballer, minute};
                }
            }

            for (int i = 0; i < score2; i++) {

                readGoalInformation(footballer, minute, fin, line);
                scorersWithGoalsAndMinutes[footballer].push_back(minute);

                if (!footballerTeams.contains(footballer)) {
                    footballerTeams[footballer] = team2;
                }

                if (i == 0) {
                    openerTeam2 = {footballer, minute};
                }
            }

            if (openerTeam1.second < openerTeam2.second) {
                teamsTable[team1][2] += 1;
                footballerOpens[openerTeam1.first]++;
            } else if (openerTeam1.second > openerTeam2.second) {
                teamsTable[team2][2] += 1;
                footballerOpens[openerTeam2.first]++;
            }

            bringGoalsInfoToPrefixSums(scorersWithGoalsAndMinutes, footballerGoals);
            scorersWithGoalsAndMinutes.clear();
        } else {
            requestType = determineRequestType(line);

            switch (requestType) {
                case 1:
                    processRequestType1(line, teamsTable);
                    break;
                case 2:
                    processRequestType2(line, teamsTable);
                    break;
                case 3:
                    processRequestType3(line, footballerGoals);
                    break;
                case 4:
                    processRequestType4(line, teamsTable, footballerTeams, footballerGoals);
                    break;
                case 5:
                    processRequestType5(line, footballerGoals);
                    break;
                case 6:
                    processRequestType6(line, footballerGoals);
                    break;
                case 7:
                    processRequestType7(line, footballerGoals);
                    break;
                case 8:
                    processRequestType8(line, teamsTable);
                    break;
                case 9:
                    processRequestType9(line, footballerOpens);
                    break;
            }
        }
    }
}

int main() {
    solve();

    return 0;
}
