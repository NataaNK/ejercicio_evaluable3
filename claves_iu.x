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
    string error_msg<>;
};

struct Response {
    int result;
    string error_msg<>;
};

program CLAVES_PROG {
    version CLAVES_VERS {
        int INIT(void) = 1;
        Response SET_VALUE(SetValueArgs) = 2;
        GetValueResponse GET_VALUE(int) = 3; 
        Response DELETE_KEY(int) = 4;
        Response MODIFY_VALUE(SetValueArgs) = 5;
        int EXIST(int) = 6;
    } = 1;
} = 99;


