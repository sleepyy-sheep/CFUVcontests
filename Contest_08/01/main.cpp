struct Hack {
    int trash;
    int secret;
};
int hack_it(Keeper keeper) {
    Hack* h = reinterpret_cast<Hack*>(&keeper);
    return h->secret;
}
