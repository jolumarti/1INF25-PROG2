#include "func.hpp"


bool read_paciente(ifstream &file, void *&paciente) {
    void **data;
    int id, age;
    char *name, gender, c;
    file >> id >> c;
    if (file.eof()) return false;
    name = read_line(file, ',');
    file >> age >> c >> gender;
    file.get();
    data = new void *[6]{};
    data[ID] = new int(id);
    data[NAME] = name;
    data[AGE] = new int(age);
    data[GENDER] = new char(gender);
    data[TOTAL] = new int(0);
    paciente = data;
    return true;
}

void resize_memory(void **&array, int cap, int size) {
    void **aux = new void *[cap]{};
    for (int i = 0; i < size; i++) {
        aux[i] = array[i];
    }
    if (array) delete[] array;
    array = aux;
}

void cargarPacientes(const char *file_name, void *&pacientes) {
    ifstream file;
    open_in_file(file, file_name);
    int cap{}, num{};
    void **aux_pacientes{}, *paciente{};
    while (read_paciente(file, paciente)) {
        if (cap == num) {
            cap += INCREMENT;
            resize_memory(aux_pacientes, cap, num);
        }
        aux_pacientes[num++] = paciente;
    }
    resize_memory(aux_pacientes, num + 1, num);
    pacientes = aux_pacientes;
}

int find_paciente(void *pacientes, int id) {
    if (!pacientes) return NOT_FOUND;
    void **aux_pacientes = (void **) pacientes;
    int i = 0;
    while (aux_pacientes[i]) {
        void **paciente = (void **) aux_pacientes[i];
        int *id_paciente = (int *) paciente[ID];
        if (*id_paciente == id) return i;
        i++;
    }

    return NOT_FOUND;
}

void push_visita(void **&visitas, void *visita, int &cap, int &num) {
    if (cap == num) {
        cap += INCREMENT;
        resize_memory(visitas, cap + 1, num);
    }
    visitas[num++] = visita;
}

bool read_visita(ifstream &file, void *&visita, int &id_paciente) {
    int yy, mm, dd, hour, minute, cost;
    char c;
    void **data{};
    file >> yy >> c >> mm >> c >> dd >> c;
    if (file.eof()) return false;
    file >> hour >> c >> minute >> c >> id_paciente >> c >> cost >> c;
    file.get();
    file.get();
    data = new void *[3]{};
    data[DATE] = new int(yy * 10000 + mm * 100 + dd);
    data[HOUR] = new int(hour * 100 + minute);
    data[COST] = new int(cost);
    visita = data;
    return true;
}

void delete_visita(void *&visita) {
    if (!visita) return;
    void **data = (void **) visita;
    delete (int *) data[DATE];
    delete (int *) data[HOUR];
    delete (int *) data[COST];
    delete[] data;
    visita = nullptr;
}
int size_arr(void *arr) {
    if (!arr) return 0;
    int size = 0;
    void **aux = (void **) arr;
    while (aux[size]) size++;
    return size;
}

void cargarVisitas(const char *file_name, void *pacientes) {
    ifstream file;
    open_in_file(file, file_name);
    void **aux_pacientes = (void **) pacientes;
    void *visita{};
    int size_pacientes = size_arr(pacientes);
    int id_paciente, *caps = new int[size_pacientes]{}, *nums = new int[size_pacientes]{};
    while (read_visita(file, visita, id_paciente)) {
        int pos = find_paciente(pacientes, id_paciente);
        if (pos == NOT_FOUND) {
            delete_visita(visita); continue;
        }
        void **aux_visita = (void **) visita;
        void **paciente = (void **) aux_pacientes[pos];
        void **&visitas = (void **&) paciente[VISITS];
        int *total = (int *) paciente[TOTAL];
        int *cost = (int *) aux_visita[COST];
        *total += *cost;
        push_visita(visitas, visita, caps[pos], nums[pos]);
    }
    for (int i = 0; i < size_pacientes; i++) {
        void **paciente = (void **) aux_pacientes[i];
        void **&visitas = (void **&) paciente[VISITS];
        if (visitas)resize_memory(visitas, nums[i] + 1, nums[i]);
    }
    delete [] caps;
    delete [] nums;
}


void generarReporte(const char *file_name, void *pacientes) {
    ofstream file;
    open_out_file(file, file_name);
    void **aux_pacientes = (void **) pacientes;
    int i = 0;
    void **paciente = (void **) aux_pacientes[i];
    print_filled_line(file, '=');
    file << setw(LINE_SIZE / 2+15) << "REPORTE DEL SISTEMA DE URGENCIAS" << endl;
    print_filled_line(file, '=');
    file << setw(6) << "ID" << setw(LINE_SIZE / 6+5) << "NOMBRE"
            << setw(LINE_SIZE / 6+2) << "EDAD" << setw(LINE_SIZE / 6) << "GENERO"
            << setw(LINE_SIZE / 6) << "VISITAS" << setw(LINE_SIZE / 6) << "TOTAL" << endl;
    print_filled_line(file, '-');
    while (paciente) {
        int *id = (int *) paciente[ID];
        int *age = (int *) paciente[AGE];
        char *name = (char *) paciente[NAME];
        char *gender = (char *) paciente[GENDER];
        int *total = (int *) paciente[TOTAL];
        file << *id << setw(LINE_SIZE / 6+5) << name
                << setw(LINE_SIZE / 6) << *age << setw(LINE_SIZE / 6) << *gender
                << setw(LINE_SIZE / 6) << size_arr(paciente[VISITS]) << setw(LINE_SIZE / 6) << *total << endl;
        paciente = (void **) aux_pacientes[++i];
    }
}
