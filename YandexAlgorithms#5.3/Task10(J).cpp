#include <bits/stdc++.h>

using namespace std;

struct Package {
    int indPackage; //Хранит индекс пакета
    int count; //Хранит количество данных пакетов
    unordered_set<int> devicesWithThisPackage; //Номера устройств, у которых есть этот пакет

    Package(int ind) {
        indPackage = ind;
        count = 1; //Есть у 0-устройства
        devicesWithThisPackage.insert(0);
    }

    void updateInfo(int indDevice) {
        count++;
        devicesWithThisPackage.insert(indDevice);
    }
};

struct Device {
    int timeslots; //Хранит понадобившееся количество таймслотов

    int indDevice; //Хранит индекс устройства
    unordered_set<int> indPackages; //Хранит номера пакетов, закачанных на устройство
    unordered_set<int> indMissingPackeges; //Хранит номера пакетов, отсутствующих на устройстве
    unordered_map<int, int> donorDevices; //Хранит номера устройств-доноров и количество пакетов от них

    //Инициализация 0-устройства
    Device(int k, bool isSource, int ind) {
        indDevice = ind;

        if (isSource) {
            for (int i = 0; i < k; i++) {
                indPackages.insert(i);
            }
        } else {
            for (int i = 0; i < k; i++) {
                indMissingPackeges.insert(i);
            }
        }
    }

    //Выбрать пакет на закачку
    int selectPackageInd(vector<Package>& packages) {

        int indRequiredPackage = -1;

        for (auto& indMissingPackage : indMissingPackeges) {

            if (indRequiredPackage == -1) {
                indRequiredPackage = indMissingPackage; //Инициализация
            } else {
                //Проходимся по индексам отсутствующих у устройства пакетов

                if (packages[indMissingPackage].count < packages[indRequiredPackage].count) { //
                    //Выбираем самый редкий пакет
                    indRequiredPackage = indMissingPackage;

                } else if (packages[indMissingPackage].count == packages[indRequiredPackage].count) {
                    //Если таких пакетов несколько, выбираем пакет с наименьшим номером
                    indRequiredPackage = min(indMissingPackage, indRequiredPackage);
                }
            }


        }

        return indRequiredPackage;
    }

    //Выбрать устройство, у которого будет запрошен выбранный ранее пакет
    int selectDonorDeviceInd(int indPackage, vector<Device>& devices, vector<Package>& packages) {

        int indDonorDevice = -1;

        for (auto& indPotentialDonor : packages[indPackage].devicesWithThisPackage) {
            if (indDonorDevice == -1) {
                indDonorDevice = indPotentialDonor; //Инициализация
            } else {
                //Проходимся по индексам устройств, у которых есть выбранный пакет

                if (indPotentialDonor != indDevice) { //Потенциальный донор отличен от текущего
                    if (devices[indPotentialDonor].indPackages.size() <
                        devices[indDonorDevice].indPackages.size()) {

                        //Если таких устройств несколько, выбираем устройство с наименьшим количеством пакетов
                        indDonorDevice = indPotentialDonor;

                    } else if (devices[indPotentialDonor].indPackages.size() ==
                               devices[indDonorDevice].indPackages.size()) {

                        //Если и таких устройств несколько, выбираем устройство с наименьшим количеством пакетов
                        indDonorDevice = min(indPotentialDonor, indDonorDevice);
                    }
                }
            }
        }

        return indDonorDevice;
    }

    //Выбрать устройство, чей запрос будет удовлетворён (ALERT)
    int selectRecipientDeviceInd(unordered_map<int, int>& requestedDevices, vector<Device>& devices) {
        int indRecipientDevice = -1;
        int indRequestedDevice;

        for (auto& requestedDevice : requestedDevices) {

            indRequestedDevice = requestedDevice.first;

            if (indRecipientDevice == -1) {
                indRecipientDevice = indRequestedDevice;
            } else {
                //Проходимся по индксам устройств, запросивших пакет у данного

                if (donorDevices[indRequestedDevice] > donorDevices[indRecipientDevice]) {
                    //Выбираем устройство, от которого было получено больше всего пакетов

                    indRecipientDevice = indRequestedDevice;

                } else if (donorDevices[indRequestedDevice] == donorDevices[indRecipientDevice]) {
                    //Если таких устройств несколько, выбираем устройство с наименьшим количеством пакетов

                    if (devices[indRequestedDevice].indPackages.size() <
                        devices[indRecipientDevice].indPackages.size()) {

                        indRecipientDevice = indRequestedDevice;
                    } else if (devices[indRequestedDevice].indPackages.size() ==
                               devices[indRecipientDevice].indPackages.size()) {

                        //Если и таких устройств несколько, выбираем устройство с наименьшим количеством пакетов
                        indRecipientDevice = min(indRequestedDevice, indRecipientDevice);
                    }
                }
            }
        }

        return indRecipientDevice;
    }

    //Загрузить пакет от респондента
    void addPackage(int indRespondent, int packageInd) {
        indPackages.insert(packageInd);
        indMissingPackeges.erase(packageInd);

        donorDevices[indRespondent]++;
    }

    //Проверка, все пакеты ли переданы
    bool isUpdateComplete() {
        return indMissingPackeges.empty();
    }
};

void solve() {
    int n, k;
    cin >> n >> k;

    //<-------------------------------------------------------------------------------------------------->

    vector<Device> devices; //Список всех устройств, к которым можно обращаться по индексу
    devices.push_back(Device(k, true, 0)); //Инициализация устройства, на которое изначально скачано обновление

    for (int i = 1; i < n; i++) {
        devices.push_back(Device(k, false, i)); //Инициализация остальных устройств
    }

    //<-------------------------------------------------------------------------------------------------->

    vector<Package> packages; //Список всех пакетов, к которым можно обращаться по индексу
    for (int i = 0; i < k; i++) {
        packages.push_back(Package(i)); //Инициализация остальных устройств
    }

    //<-------------------------------------------------------------------------------------------------->

    int indRequiredPackage; //Индекс запрашиваемого пакета
    int indDonorDevice; //Индекс устройства, у которого будет запрошен пакет

    //Таблица {устройство, которому отправили запрос - [индекс запросившего устройство, индекс пакета]}
    unordered_map<int, unordered_map<int, int>> requestsTable;
    //Таблица {устройство, которому отправили запрос - индекс выбранного запросившего устройств
    unordered_map<int, unordered_map<int, int>> responsesTable;

    int indRecepient;

    //<-------------------------------------------------------------------------------------------------->

    //Список индексов оставшихся устройств, по которым можно ссылаться на них как devices[ind]
    set<int> indRemainingDevices;

    //Изначально ни у одного устройства, кроме 0-устройства, нет всех пакетов
    for (int i = 1; i < n; i++) {
        indRemainingDevices.insert(i);
    }

    int timeslots = 1;
    while (!indRemainingDevices.empty()) { //Пока есть устройство, у которого ещё не скачаны все пакетцы

        //Отправка запросов
        for (auto& indRemainingDevice : indRemainingDevices) { //Каждое устройство, не загрузившее все пакеты

            //Устройство выбирает пакет для закачки
            indRequiredPackage = devices[indRemainingDevice].selectPackageInd(packages);

            //Устройство выбирает устройство, которому нужно отправить запрос
            indDonorDevice = devices[indRemainingDevice].
                    selectDonorDeviceInd(indRequiredPackage, devices, packages);

            //Устройство осуществляет запрос, добавляя его в таблицу запросов
            requestsTable[indDonorDevice][indRemainingDevice] = indRequiredPackage;
        }

        //Обработка запросов
        for (auto& request : requestsTable) {

            int indRespondent = request.first; //Текущий ответчик

            //Выбор рецепиента, чей запрос будет удовлетворён
            indRecepient = devices[indRespondent].selectRecipientDeviceInd(request.second, devices);

            responsesTable[indRespondent][indRecepient] = request.second[indRecepient];
        }

        for (auto& respons : responsesTable) {

            for (auto& recepient : respons.second) {
                //Удовлетворение запроса ДОЛЖНО БЫТЬ ПОСЛЕ
                devices[recepient.first].addPackage(respons.first, respons.second[recepient.first]);

                //Обновление информации у переданного пакета о его количестве и обладателях
                packages[respons.second[recepient.first]].updateInfo(recepient.first); //Рецепиент стал облатаделем

                //Если репециент полностью обновился
                if (devices[recepient.first].isUpdateComplete()) {

                    //Вычеркнуть из списка оставшихся устройств
                    indRemainingDevices.erase(recepient.first);

                    //Установить количество таймслотов для данного устройства в текущее
                    devices[recepient.first].timeslots = timeslots;
                }
            }

        }

        requestsTable.clear();
        responsesTable.clear();

        timeslots++;
    }

    for (int i = 1; i < n; i++) {
        cout << devices[i].timeslots << " ";
    }
    cout << "\n";
}

int main() {
    solve();

    return 0;
}