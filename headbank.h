struct currency
    {
    char currency_name[10];
    char letter_code[4];
    int currency_code;
    };

struct client
    {
    long long int identification_number;
    int account;
    int amount;
    int code;
    };

struct key
    {
    int ind_num;
    int key_1;
    int key_2;
    int key_3;
    };

struct balance
    {
    int currency_start[5];
    int currency_cipher[5];
    };

void code_encryption (int N, struct client *bank, struct client*bank_ciphr, struct key *ciphr);

int find_code_key (struct client *bank, int i);

long long int combination (int n, int m);

int factorial (int n, int i, int res);

unsigned check_bit (char *in, unsigned i);

void set_bit (char *in, unsigned i);

int resheto (int n);

void account_encryption (int N, struct client *bank, struct client *bank_ciphr, struct key *ciphr);

int Verification (int N, struct client *bank, struct client *bank_new);

int Check (struct balance *total_balance);

void amount_encryption (int N, struct client *bank, struct client *bank_ciphr, struct key *ciphr);

int nod (int n, int n1);

void decryption (int N, struct client *bank_cipher, struct client *bank_new, struct key *cipher, struct balance *total_balance);

void print(struct balance *total_balance, struct currency *val);

void currency_reference (struct currency *val);

void customer_base (int N, struct client *bank,  struct currency *val, struct balance *total_balance);
