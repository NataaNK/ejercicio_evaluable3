#!/bin/bash

parentDir="$(dirname "$(pwd)")"   # Directorio del proyecto

make &> /dev/null

export LD_LIBRARY_PATH="${parentDir}/ejercicio_evaluable3/libclaves.so":$LD_LIBRARY_PATH
export LD_LIBRARY_PATH="${parentDir}/ejercicio_evaluable3/cJSON":$LD_LIBRARY_PATH
export IP_TUPLAS=localhost        # EJECUTAR SERVIDOR EN MISMA MÁQUINA


client_exec="${parentDir}/ejercicio_evaluable3/cliente"             # Ejecutable del cliente
server_exec="${parentDir}/ejercicio_evaluable3/servidor"            # Ejecutable del servidor
data="${parentDir}/ejercicio_evaluable3/data.json"                  # Directorio de datos
tests_jsons="${parentDir}/ejercicio_evaluable3/tests_files/json_expecteds"      # Directorio de jsons esperados
test_txts="${parentDir}/ejercicio_evaluable3/tests_files/txt_expecteds"         # Directorio de txts esperados
output="${parentDir}/ejercicio_evaluable3/tests_files/output.txt"         # Directorio de la salida

tests_passed=0




echo ""
echo "Prueba 1: Value1 no es un string"
$client_exec 0 > $output &
pid1=$!
wait $pid1

diffResult2=$(diff "$output" "${test_txts}/output_SIGSEV.txt")

if [ "$diffResult2" == "" ]; then
    echo "TEST 1 PASSED"
    ((tests_passed++))
else
    echo "TEST 1 FAILED - $diffResult1 - $diffResult2"
fi





$client_exec 1 > $output &
pid1=$!
wait $pid1

echo ""
echo "Prueba 2: Init()"
diffResult1=$(diff "$data" "${tests_jsons}/prueba2-10.json")
diffResult2=$(diff "$output" "${test_txts}/output_prueba2-10.txt")

if [ "$diffResult1" == "" ] && [ "$diffResult2" == "" ]; then
    echo "TEST 2 PASSED"
    ((tests_passed++))
else
    echo "TEST 2 FAILED - $diffResult1 - $diffResult2"
fi





echo ""
echo "Prueba 3: Value1 no es un string menor o igual de 256 chars"
diffResult1=$(diff "$data" "${tests_jsons}/prueba2-10.json")
diffResult2=$(diff "$output" "${test_txts}/output_prueba2-10.txt")

if [ "$diffResult1" == "" ] && [ "$diffResult2" == "" ]; then
    echo "TEST 3 PASSED"
    ((tests_passed++))
else
    echo "TEST 3 FAILED - $diffResult1 - $diffResult2"
fi


echo ""
echo "Prueba 4: Value2_N no es un int menor o igual que 32"
diffResult1=$(diff "$data" "${tests_jsons}/prueba2-10.json")
diffResult2=$(diff "$output" "${test_txts}/output_prueba2-10.txt")

if [ "$diffResult1" == "" ] && [ "$diffResult2" == "" ]; then
    echo "TEST 4 PASSED"
    ((tests_passed++))
else
    echo "TEST 4 FAILED - $diffResult1 - $diffResult2"
fi




echo ""
echo "Prueba 5: *Value1 o *N_value o *V_value2 no son punteros válidos"
diffResult1=$(diff "$data" "${tests_jsons}/prueba2-10.json")
diffResult2=$(diff "$output" "${test_txts}/output_prueba2-10.txt")

if [ "$diffResult1" == "" ] && [ "$diffResult2" == "" ]; then
    echo "TEST 5 PASSED"
    ((tests_passed++))
else
    echo "TEST 5 FAILED - $diffResult1 - $diffResult2"
fi




echo ""
echo "Prueba 6: Set_value()"
diffResult1=$(diff "$data" "${tests_jsons}/prueba2-10.json")
diffResult2=$(diff "$output" "${test_txts}/output_prueba2-10.txt")

if [ "$diffResult1" == "" ] && [ "$diffResult2" == "" ]; then
    echo "TEST 6 PASSED"
    ((tests_passed++))
else
    echo "TEST 6 FAILED - $diffResult1 - $diffResult2"
fi




echo ""
echo "Prueba 7: Get_value()"
diffResult1=$(diff "$data" "${tests_jsons}/prueba2-10.json")
diffResult2=$(diff "$output" "${test_txts}/output_prueba2-10.txt")

if [ "$diffResult1" == "" ] && [ "$diffResult2" == "" ]; then
    echo "TEST 7 PASSED"
    ((tests_passed++))
else
    echo "TEST 7 FAILED - $diffResult1 - $diffResult2"
fi




echo ""
echo "Prueba 8: Modify_value()"
diffResult1=$(diff "$data" "${tests_jsons}/prueba2-10.json")
diffResult2=$(diff "$output" "${test_txts}/output_prueba2-10.txt")

if [ "$diffResult1" == "" ] && [ "$diffResult2" == "" ]; then
    echo "TEST 8 PASSED"
    ((tests_passed++))
else
    echo "TEST 8 FAILED - $diffResult1 - $diffResult2"
fi




echo ""
echo "Prueba 9: Delete_key()"
diffResult1=$(diff "$data" "${tests_jsons}/prueba2-10.json")
diffResult2=$(diff "$output" "${test_txts}/output_prueba2-10.txt")

if [ "$diffResult1" == "" ] && [ "$diffResult2" == "" ]; then
    echo "TEST 9 PASSED"
    ((tests_passed++))
else
    echo "TEST 9 FAILED - $diffResult1 - $diffResult2"
fi



echo ""
echo "Prueba 10: Exists()"
diffResult1=$(diff "$data" "${tests_jsons}/prueba2-10.json")
diffResult2=$(diff "$output" "${test_txts}/output_prueba2-10.txt")

if [ "$diffResult1" == "" ] && [ "$diffResult2" == "" ]; then
    echo "TEST 10 PASSED"
    ((tests_passed++))
else
    echo "TEST 10 FAILED - $diffResult1 - $diffResult2"
fi




echo ""
echo "Prueba 11: Mezcla de operaciones entre usuarios: set y get"
$client_exec 2 > /dev/null 2>&1 &
pid1=$!
$client_exec 3 > /dev/null 2>&1 &
pid2=$!
wait $pid1 $pid2

diffResult1=$(diff "$data" "${tests_jsons}/setget.json")

if [ "$diffResult1" == "" ]; then
  echo "TEST 11 PASSED"
  ((tests_passed++))
else
  echo "TEST 11 FAILED - $diffResult1"
fi


$client_exec 5 > /dev/null 2>&1 &
pid1=$!
wait $pid1
echo ""
echo "Prueba 12: Mezcla de operaciones entre usuarios: set y modify"
$client_exec 2 > /dev/null 2>&1 &
pid1=$!
$client_exec 4 > /dev/null 2>&1 &
pid2=$!
wait $pid1 $pid2

diffResult1=$(diff "$data" "${tests_jsons}/setmodify_1.json")
diffResult2=$(diff "$data" "${tests_jsons}/setmodify_2.json")

if [ "$diffResult1" == "" ] || [ "$diffResult2" == "" ]; then
  echo "TEST 12 PASSED"
  ((tests_passed++))
else
  echo "TEST 12 FAILED - $diffResult1 - $diffResult2"
fi



$client_exec 5 > /dev/null 2>&1 &
pid1=$!
wait $pid1
echo ""
echo "Prueba 13: Mezcla de operaciones entre usuarios: set y delete"
$client_exec 2 > /dev/null 2>&1 &
pid1=$!
$client_exec 5 > /dev/null 2>&1 &
pid2=$!
wait $pid1 $pid2

diffResult1=$(diff "$data" "${tests_jsons}/setdelete_1.json")
diffResult2=$(diff "$data" "${tests_jsons}/setdelete_2.json")

if [ "$diffResult1" == "" ] || [ "$diffResult2" == "" ]; then
  echo "TEST 13 PASSED"
  ((tests_passed++))
else
  echo "TEST 13 FAILED - $diffResult1 - $diffResult2"
fi



$client_exec 5 > /dev/null 2>&1 &
pid1=$!
wait $pid1
echo ""
echo "Prueba 14: Mezcla de operaciones entre usuarios: set y exist"
$client_exec 2 > /dev/null 2>&1 &
pid1=$!
$client_exec 6 > /dev/null 2>&1 &
pid2=$!
wait $pid1 $pid2

diffResult1=$(diff "$data" "${tests_jsons}/setexist_1.json")
diffResult2=$(diff "$data" "${tests_jsons}/setexist_2.json")

if [ "$diffResult1" == "" ] || [ "$diffResult2" == "" ]; then
  echo "TEST 14 PASSED"
  ((tests_passed++))
else
  echo "TEST 14 FAILED - $diffResult1"
fi



echo ""
echo "Prueba 15: Mezcla de operaciones entre usuarios: get y modify"
$client_exec 3 > /dev/null 2>&1 &
pid1=$!
$client_exec 4 > /dev/null 2>&1 &
pid2=$!
wait $pid1 $pid2

diffResult1=$(diff "$data" "${tests_jsons}/getmodify.json")

if [ "$diffResult1" == "" ]; then
  echo "TEST 15 PASSED"
  ((tests_passed++))
else
  echo "TEST 15 FAILED - $diffResult1"
fi




echo ""
echo "Prueba 16: Mezcla de operaciones entre usuarios: get y delete"
$client_exec 3 > /dev/null 2>&1 &
pid1=$!
$client_exec 5 > /dev/null 2>&1 &
pid2=$!
wait $pid1 $pid2

diffResult1=$(diff "$data" "${tests_jsons}/getdelete.json")

if [ "$diffResult1" == "" ]; then
  echo "TEST 16 PASSED"
  ((tests_passed++))
else
  echo "TEST 16 FAILED - $diffResult1"
fi




$client_exec 2 > /dev/null 2>&1 &
pid1=$!
wait $pid1
echo ""
echo "Prueba 17: Mezcla de operaciones entre usuarios: modify y delete"
$client_exec 4 > /dev/null 2>&1 &
pid1=$!
$client_exec 5 > /dev/null 2>&1 &
pid2=$!
wait $pid1 $pid2

diffResult1=$(diff "$data" "${tests_jsons}/modifydelete.json")

if [ "$diffResult1" == "" ]; then
  echo "TEST 17 PASSED"
  ((tests_passed++))
else
  echo "TEST 17 FAILED - $diffResult1"
fi




$client_exec 2 > /dev/null 2>&1 &
pid1=$!
wait $pid1
echo ""
echo "Prueba 18: Mezcla de operaciones entre usuarios: delete y exist"
$client_exec 5 > /dev/null 2>&1 &
pid1=$!
$client_exec 6 > /dev/null 2>&1 &
pid2=$!
wait $pid1 $pid2

diffResult1=$(diff "$data" "${tests_jsons}/deleteexist.json")

if [ "$diffResult1" == "" ]; then
  echo "TEST 18 PASSED"
  ((tests_passed++))
else
  echo "TEST 18 FAILED - $diffResult1"
fi




echo ""
echo "Prueba 19: 5 clientes simultáneos"
$client_exec 4 > /dev/null 2>&1 & 
$client_exec 5 > /dev/null 2>&1 &
$client_exec 7 > /dev/null 2>&1 &
$client_exec 8 > /dev/null 2>&1 &
$client_exec 9 > /dev/null 2>&1 
# No ha saltado error
echo "TEST 19 PASSED"
((tests_passed++))




echo ""
echo "Prueba 20: 10 clientes simultáneos"
$client_exec 4 > /dev/null 2>&1 &
$client_exec 5 > /dev/null 2>&1 &
$client_exec 7 > /dev/null 2>&1 &
$client_exec 8 > /dev/null 2>&1 &
$client_exec 9 > /dev/null 2>&1 &
$client_exec 4 > /dev/null 2>&1 &
$client_exec 5 > /dev/null 2>&1 &
$client_exec 7 > /dev/null 2>&1 &
$client_exec 8 > /dev/null 2>&1 &
$client_exec 9 > /dev/null 2>&1 
# No ha saltado error
echo "TEST 20 PASSED"
((tests_passed++))




echo ""
echo "Prueba 21: 20 clientes simultáneos"
$client_exec 4 > /dev/null 2>&1 &
pid1=$!
$client_exec 5 > /dev/null 2>&1 &
pid2=$!
$client_exec 7 > /dev/null 2>&1 &
pid3=$!
$client_exec 8 > /dev/null 2>&1 &
pid4=$!
$client_exec 9 > /dev/null 2>&1 &
pid5=$!
$client_exec 4 > /dev/null 2>&1 &
pid6=$!
$client_exec 5 > /dev/null 2>&1 &
pid7=$!
$client_exec 7 > /dev/null 2>&1 &
pid8=$!
$client_exec 8 > /dev/null 2>&1 &
pid9=$!
$client_exec 9 > /dev/null 2>&1 &
pid10=$!
$client_exec 4 > /dev/null 2>&1 &
pid11=$!
$client_exec 5 > /dev/null 2>&1 &
pid12=$!
$client_exec 7 > /dev/null 2>&1 &
pid13=$!
$client_exec 8 > /dev/null 2>&1 &
pid14=$!
$client_exec 10 > /dev/null 2>&1 &
pid15=$!
$client_exec 4 > /dev/null 2>&1 &
pid16=$!
$client_exec 5 > /dev/null 2>&1 &
pid17=$!
$client_exec 7 > /dev/null 2>&1 &
pid18=$!
$client_exec 8 > /dev/null 2>&1 &
pid19=$!
$client_exec 9 > /dev/null 2>&1 &
pid20=$!
wait $pid1 $pid2 $pid3 $pid4 $pid5 $pid6 $pid7 $pid8 $pid9 $pid10 $pid11 $pid12 $pid13 $pid14 $pid15 $pid16 $pid17 $pid18 $pid19 $pid20
# No ha saltado error
echo "TEST 21 PASSED"
((tests_passed++))


$client_exec 15 &
pid1=$!
wait $pid1

echo ""
echo "Prueba 22: Set_value() la clave ya existe"
$client_exec 11 > $output &
pid1=$!
wait $pid1
diffResult1=$(diff "$output" "${test_txts}/output_prueba22.txt")

if [ "$diffResult1" == "" ]; then
  echo "TEST 22 PASSED"
  ((tests_passed++))
else
  echo "TEST 22 FAILED - $diffResult1"
fi




echo ""
echo "Prueba 23: Get_value() la clave no existe"
$client_exec 12 > $output &
pid1=$!
wait $pid1
diffResult1=$(diff "$output" "${test_txts}/output_prueba23.txt")

if [ "$diffResult1" == "" ]; then
  echo "TEST 23 PASSED"
  ((tests_passed++))
else
  echo "TEST 23 FAILED - $diffResult1"
fi




echo ""
echo "Prueba 24: Modify_value() la clave no existe"
$client_exec 13 > $output &
pid1=$!
wait $pid1
diffResult1=$(diff "$output" "${test_txts}/output_prueba24.txt")

if [ "$diffResult1" == "" ]; then
  echo "TEST 24 PASSED"
  ((tests_passed++))
else
  echo "TEST 24 FAILED - $diffResult1"
fi




echo ""
echo "Prueba 25: Delete_value() la clave no existe"
$client_exec 14 > $output &
pid1=$!
wait $pid1
diffResult1=$(diff "$output" "${test_txts}/output_prueba25.txt")

if [ "$diffResult1" == "" ]; then
  echo "TEST 25 PASSED"
  ((tests_passed++))
else
  echo "TEST 25 FAILED - $diffResult1"
fi


echo ""
echo "Passed $tests_passed of 25 tests"