//
// Created by yusuf on 1/1/23.
//

#ifndef DSAPRO_CIRCULARDOUBLY_H
#define DSAPRO_CIRCULARDOUBLY_H


using namespace std;
struct nod {
    int info;
    struct nod *n;
    struct nod *p;
}*start, *last;

class circulardoublylist {
public:
    int count = 0;
    circulardoublylist() {
        start = NULL;
        last = NULL;
    }

    nod* create_node(int v) {
        count++;
        struct nod *t;
        t = new(struct nod);
        t->info = v;
        t->n = NULL;
        t->p = NULL;
        return t;
    }

    void insert_begin(int v) {
        struct nod *t;
        t = create_node(v);
        if (start == last && start == NULL) {
            start = last = t;
            start->n = last->n = NULL;
            start->p = last->p = NULL;
        } else {
            t->n = start;
            start->p = t;
            start = t;
            start->p = last;
            last->n = start;
        }
    }
    void insert_end(int v) {
        struct nod *t;
        t = create_node(v);
        if (start == last && start == NULL) {
            start = last = t;
            start->n= last->n = NULL;
            start->p = last->p= NULL;
        } else {
            last->n= t;
            t->p= last;
            last = t;
            start->p = last;
            last->n= start;
        }
    }


    string delete_pos(int pos) {
        string ans;
        int i;
        nod *ptr, *s;
        if (start == last && start == NULL) {
            return "Empty";
        }
        if (count < pos) {
            return "!in range";
        }
        s = start;
        if(pos == 1) {
            count--;
            last->n = s->n;
            s->n->p = last;
            start = s->n;
            free(s);
            return "Deleted";
        }
        for (i = 0;i < pos - 1;i++ ) {
            s = s->n;
            ptr = s->p;
        }
        ptr->n = s->n;
        s->n->p = ptr;
        if (pos == count) {
            last = ptr;
        }
        count--;
        free(s);
        return "Deleted";
    }

    string search(int v) {
        string ans;
        int i;
        bool flag = false;
        struct nod *s;
        if (start == last && start == NULL) {
            ans= "Empty";
        }
        s = start;
        for (i = 0;i < count;i++) {
            if (s->info == v) {
                ans= "Found";
                flag = true;
            }
            s = s->n;
        }
        if (!flag){
            ans= "!Found";
        }
        return ans;
    }

    string display() {
        string ans;
        int i;
        struct nod *s;
        if (start == last && start == NULL) {
            return "The List is empty, nothing to display";
        }
        s = start;
        for (i = 0;i < count-1;i++) {
            ans+=to_string(s->info)+" ";
            s = s->n;
        }
        ans+=to_string(s->info)+" ";
        return ans;
    }

};

#endif //DSAPRO_CIRCULARDOUBLY_H
