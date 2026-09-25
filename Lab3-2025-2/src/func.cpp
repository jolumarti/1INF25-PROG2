#include "func.hpp"

void resize_memory(void **&array, int cap, int size) {
    void **aux = new void *[cap]{};
    for (int i = 0; i < size; i++) {
        aux[i] = array[i];
    }
    if (array) delete[] array;
    array = aux;
}

int size_arr(void *arr) {
    if (!arr) return 0;
    int size = 0;
    void **aux = (void **) arr;
    while (aux[size]) size++;
    return size;
}

bool read_streamer(ifstream &file, void *&streamer) {
    int seguidores;
    long long temp;
    char c, *cuenta, *categoria;
    cuenta = read_line(file, ',');
    if (file.eof()) {
        delete [] cuenta;
        return false;
    }
    file >> temp >> c >> temp >> c >> seguidores >> c;
    categoria = read_line(file, '\n');
    void **data = new void *[4]{};
    data[ACCOUNT] = cuenta;
    data[FOLLOWERS] = new int{seguidores};
    data[CATEGORY] = categoria;
    streamer = data;
    return true;
}

void cargastreamers(void *&streamers) {
    ifstream file;
    open_in_file(file, "../data/streamers.csv");
    void **aux_streamers{}, *streamer{};
    int cap{}, num{};
    while (read_streamer(file, streamer)) {
        if (cap == num) {
            cap += INCREMENT;
            resize_memory(aux_streamers, cap, num);
        }
        aux_streamers[num++] = streamer;
    }
    resize_memory(aux_streamers, num + 1, num);
    streamers = aux_streamers;
}

bool read_comment(ifstream &file, void *&comment) {
    char *id, *text, *sender, *receiver;
    id = read_line(file, ',');
    if (file.eof()) {
        delete [] id;
        return false;
    }
    text = read_line(file, '[');
    sender = read_line(file, ' ');
    receiver = read_line(file, ']');
    file.get();
    void **data = new void *[4]{};
    data[ID] = id;
    data[TEXT] = text;
    data[SENDER] = sender;
    data[RECEIVER] = receiver;
    comment = data;
    return true;
}

void cargacomentarios(void *&comentarios) {
    ifstream file;
    open_in_file(file, "../data/comentarios.csv");
    void **aux_comments{}, *comment{};
    int cap{}, num{};
    while (read_comment(file, comment)) {
        if (cap == num) {
            cap += INCREMENT;
            resize_memory(aux_comments, cap, num);
        }
        aux_comments[num++] = comment;
    }
    resize_memory(aux_comments, num + 1, num);
    comentarios = aux_comments;
}

void insert_comments(void **&comments, void *comentarios, const char *account) {
    if (!comentarios) return;
    int num{}, cap{}, i{};
    void **aux_comentarios = (void **) comentarios;
    void **aux_comment = (void **) aux_comentarios[i];
    while (aux_comment) {
        char *sender = (char *) aux_comment[SENDER];
        if (strcmp(sender, account) == 0) {
            if (num == cap) {
                cap += INCREMENT;
                resize_memory(comments, cap, num);
            }
            void **comment = new void *[2];
            comment[S_RECEIVER] = copy_cstring((char *) aux_comment[RECEIVER]);
            comment[S_TEXT] = copy_cstring((char *) aux_comment[TEXT]);
            comments[num++] = comment;
        }
        aux_comment = (void **) aux_comentarios[++i];
    }
    resize_memory(comments, num + 1, num);
}

void actualizacomentarios(void *streamers, void *comentarios) {
    void **aux_streamers = (void **) streamers;
    int i = 0;
    void **streamer = (void **) aux_streamers[i];
    while (streamer) {
        void **&comments = (void **&) streamer[COMMENTS];
        char *account = (char *) streamer[ACCOUNT];
        insert_comments(comments, comentarios, account);
        streamer = (void **) aux_streamers[++i];
    }
}

void imprimestreamers(void *streamers) {
    ofstream file;
    open_out_file(file, "../dist/Reporte.txt");
    void **aux_streamers = (void **) streamers;
    int i = 0, w = 20;
    void **streamer = (void **) aux_streamers[i];
    while (streamer) {
        void **comments = (void **) streamer[COMMENTS];
        char *account = (char *) streamer[ACCOUNT];
        int *followers = (int *) streamer[FOLLOWERS];
        print_filled_line(file, '=');
        file << left << setw(w) << "Cuenta" << "Seguidores" << endl;
        file << setw(w) << account << *followers << endl;
        print_filled_line(file, '-');

        if (comments && comments[0]) {
            file << "Comentarios Emitidos:" << endl;
            print_filled_line(file, '-');
            file << setw(w) << "Receptor" << "Texto" << endl;
            print_filled_line(file, '-');

            int i = 0;
            void **comment = (void **) comments[i];
            while (comment) {
                char *receiver = (char *) comment[S_RECEIVER];
                char *text = (char *) comment[S_TEXT];
                file << setw(w) << receiver << text << endl;
                comment = (void **) comments[++i];
            }
        } else file << "No hay comentarios" << endl;
        streamer = (void **) aux_streamers[++i];
    }
}
