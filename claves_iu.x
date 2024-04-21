struct SetValueArgs {
    int key;
    string value1<>;
    int N_value2;
    double V_value2<>;
};

struct GetValueResponse {
    string value1<>; 
    int N_value2;      
    double V_value2<>;  
};

program CLAVES_PROG {
    version CLAVES_VERS {
        int INIT(void) = 1;
        int SET_VALUE(SetValueArgs) = 2;
        GetValueResponse GET_VALUE(int) = 3; 
        int DELETE_KEY(int) = 4;
        int MODIFY_VALUE(SetValueArgs) = 5;
        int EXIST(int) = 6;
    } = 1;
} = 99;


