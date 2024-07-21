#include <bits/stdc++.h>

#define int long long

using namespace std;

void buildPrefixVoices(vector<int>& prefixVoices, vector<int>& voices) {
    prefixVoices[0] = voices[0];

    for (int i = 1; i < voices.size(); i++) {
        prefixVoices[i] = prefixVoices[i - 1] + voices[i];
    }
}

bool isDecreasing(int aimV, int ourV, unordered_map<int, int>& indLastPartWithLargeVote,
                  vector<int>& prefixVoices) {

    int down;
    if (prefixVoices.size() == 2 && indLastPartWithLargeVote[aimV] == -1) {
        down = 1;
    } else if (indLastPartWithLargeVote[aimV] == -1) {
        return 0;
    } else {
        down = prefixVoices[indLastPartWithLargeVote[aimV]] - (indLastPartWithLargeVote[aimV] + 1) * (aimV - 1);
    }

    int rise = aimV - ourV;

/*
    cout << "V = " << aimV << " down = " << down << " & rise = " << rise << endl;
    cout << "---> abs diff = " << abs(down - rise) << endl;
    cout << endl;
*/
    return rise - down >= 0; //ALERT


}

int leftBinSearch(int part, unordered_map<int, int>& indLastPartWithLargeVote,
                  vector<int>& prefixVoices, vector<int>& voices) {

    int l = 0;
    int r = 1000001;
    int mid; //Количество голосов для данной партии

    while (l != r) {
        mid = (l + r) / 2;

        if (isDecreasing(mid, voices[part], indLastPartWithLargeVote, prefixVoices)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
/*
    cout << " OptimumVoice = " << l << endl;

    cout << "Part = " << part << " & voices = " << voices[part] << ", buy = " << l - voices[part] << " voices" << endl;
*/
    return (l - voices[part]); // ALERT!
}

void solve() {
    ifstream fin("input.txt");

    int n;
    fin >> n;


    vector<int> sourceVoices(n);
    unordered_map<int, vector<pair<int, int>>> voicesWithPart; //Голоса и сколько партий столько набрали

    int v, p;

    for (int i = 0; i < n; i++) {
        fin >> v >> p;

        sourceVoices[i] = v;
        voicesWithPart[v].push_back({i + 1, p});
    }

    vector<int> voices(n);
    for (int i = 0; i < n; i++) {
        voices[i] = sourceVoices[i];
    }
    sort(voices.rbegin(), voices.rend());

    //<------------------------------------------------------------------------------------------------->

    vector<int> uniqVoices;
    uniqVoices.push_back(voices[0]);

    for (int i = 1; i < n; i++) {
        if (voices[i] != voices[i - 1]) {
            uniqVoices.push_back(voices[i]);
        }
    }

    vector<pair<int, int>> sortedParts;

    for (int i = 0; i < uniqVoices.size(); i++) {
        //cout << "V = " << uniqVoices[i] << endl;
        for (auto& equalVotesPart : voicesWithPart[uniqVoices[i]]) {
            //cout << "-> " << equalVotesPart.first << " | " << equalVotesPart.second << endl;
            sortedParts.push_back(equalVotesPart);
        }
    }

    //Вывод партий в их порядке невозрастания голосов
    /*
    cout << "Sorted parts" << endl;
    for (int i = 0; i < n; i++) {
        cout << "v = " << voices[i] << " | " << sortedParts[i].first << " & " << sortedParts[i].second << endl;
    }
    cout << endl;*/

    //<------------------------------------------------------------------------------------------------->

    vector<int> prefixVoices(n);
    buildPrefixVoices(prefixVoices, voices);

    //<------------------------------------------------------------------------------------------------->

    int lastPart = 0;
    int currV = voices[0] - 1;

    unordered_map<int, int> indLastPartWithLargeVote;
    indLastPartWithLargeVote[voices[0]] = -1;

    if (voices[0] != voices[1]) {
        indLastPartWithLargeVote[voices[0]] = 0;
    }

    while (currV >= voices[voices.size() - 1]) {
        if (currV < voices[lastPart + 1]) {
            lastPart++;
        }

        indLastPartWithLargeVote[currV] = lastPart;
        currV--;
    }

    //<------------------------------------------------------------------------------------------------->

    vector<int> voicesToWin(n);
    for (int i = 0; i < n; i++) {
        if (voices[i] == voices[0] && voices[1] != voices[0]) {
            voicesToWin[i] = 0;
        } else {
            voicesToWin[i] = leftBinSearch(i, indLastPartWithLargeVote, prefixVoices, voices);
        }
    }
/*
    cout << endl << "Print voices to win for parts" << endl;
    for (int i = 0; i < n; i++) {
        cout << voicesToWin[i] << " " << endl;
    }
    cout << endl;*/

    //<------------------------------------------------------------------------------------------------->

    vector<int> sums(n);

    for (int i = 0; i < n; i++) {
        if (sortedParts[i].second != -1) {
            sums[i] = voicesToWin[i] + sortedParts[i].second;
        } else {
            sums[i] = -1;
        }
    }
/*
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << sums[i] << endl;
    }
    cout << endl;*/

    //<------------------------------------------------------------------------------------------------->

    int indMinSum;
    int voicesOfMinSum;
    int minSum = -1;

    for (int i = 0; i < n; i++) {
        if (minSum == -1) {
            indMinSum = i;
            minSum = sums[i];
            voicesOfMinSum = minSum - sortedParts[indMinSum].second;
        } else if (sums[i] != -1 && sums[i] < minSum) {
            indMinSum = i;
            minSum = sums[i];
            voicesOfMinSum = minSum - sortedParts[indMinSum].second;
        }
    }

    //<------------------------------------------------------------------------------------------------->

    int majorityVotes = voices[indMinSum] + voicesOfMinSum;
    int selectedVotes;

    vector<int> indPartsWithLargeVote;
    //cout << "Selection" << endl;
    for (int i = 0; i < indMinSum; i++) {

        if (voices[i] >= majorityVotes) {
            indPartsWithLargeVote.push_back(i);
        }
    }
    //cout << endl;
/*
    for (auto& vot : indPartsWithLargeVote) {
        cout << voices[vot] << endl;
    }
    cout << endl;*/

    int purchasedVotes;

    //Отобрать у всех тех, кто выше цели, добирать произвольно

    for (int i = 0; i < indPartsWithLargeVote.size(); i++) {
        purchasedVotes = sourceVoices[sortedParts[indPartsWithLargeVote[i]].first - 1] - majorityVotes + 1;
        sourceVoices[sortedParts[indPartsWithLargeVote[i]].first - 1] -= purchasedVotes; // СДЕЛАТЬ ЗАМЕНУ В sourceVOICES
        sourceVoices[sortedParts[indMinSum].first - 1] += purchasedVotes;
    }

    //РАНДОМ
    int i = 0;
    int diff = majorityVotes - sourceVoices[sortedParts[indMinSum].first - 1];
    //cout << diff << endl;
    while (diff != 0) {
        if (i != sortedParts[indMinSum].first - 1) {


            if (sourceVoices[i] - diff >= 1) {
                sourceVoices[sortedParts[indMinSum].first - 1] += diff;
                sourceVoices[i] -= diff;
            } else {
                sourceVoices[sortedParts[indMinSum].first - 1] += sourceVoices[i];
                sourceVoices[i] = 0;
            }
        }

        diff = majorityVotes - sourceVoices[sortedParts[indMinSum].first - 1];
        i++;
    }
/*


    cout << "Final votes = " << majorityVotes << endl;
    cout << "Current votes = " << sourceVoices[sortedParts[indMinSum].first - 1] << endl;*/

    //<------------------------------------------------------------------------------------------------->

    //cout << "<--------------------------------------------------->" << endl;
    cout << minSum << "\n";
    cout << sortedParts[indMinSum].first << "\n";
    //cout << "FINAL" << endl;
    for (auto& source : sourceVoices) {
        cout << source << " ";
    }
    cout << "\n";
    //cout << endl;
    //cout << voicesOfMinSum << endl;
    // cout << "<--------------------------------------------------->" << endl;

    //<------------------------------------------------------------------------------------------------->
    //////////////////////////////////////////////////////
/*    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << voices[i] << endl;
    }
    cout << endl;
    //////////////////////////////////////////////////////
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << prefixVoices[i] << endl;
    }
    cout << endl;*/
    //////////////////////////////////////////////////////
    /*
    cout << endl;
    for (auto& elem : indLastPartWithLargeVote) {
        cout << "v = " << elem.first << " | lastInd = " << elem.second << endl;
    }
    cout << endl;*/
    //////////////////////////////////////////////////////
/*
    cout << endl;
    cout << voices[voices.size() - 1] << " ' " << voices[0] << endl;
    for (int h = voices[0]; h >= voices[voices.size() - 1]; h--) {
        //cout << calculateDiff(h, voices[voices.size() - 1], indLastPartWithLargeVote, prefixVoices) << endl;
        calculateDiff(h, voices[voices.size() - 1], indLastPartWithLargeVote, prefixVoices);
    }
    cout << endl;*/
    //////////////////////////////////////////////////////
    //cout << endl;
    //leftBinSearch(2, indLastPartWithLargeVote, prefixVoices, voices);
    //cout << endl;
    //////////////////////////////////////////////////////
    /// */
}

int32_t main() {
    solve();
    return 0;
}
