#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout<<endl;
    cout<<"***********************************************************"<<endl;
    cout<<"    T A B L A   D E   F R E C U E N C I A S     "<<endl;
    cout<<"***********************************************************"<<endl;
    cout<<endl;
    string respuesta;
    cout<<"Que tipo de tabla utilizara?"<<endl;
    cout<<"   1. Dado los datos recopilados (sin ordenar)"<<endl;
    cout<<"   2. Teniendo los intervalos y frecuencias de la tabla"<<endl;
    cout<<endl;
    cin>>respuesta;
    int cant_datos;
    cout<<"Introducir la cantidad de datos:"<<endl;
    cin>>cant_datos;
    float datos[cant_datos];
    float datos1[cant_datos];
    float cant_datos2 = cant_datos;
    float lon_alc;
    float aux;
    float ancl[999];
    int sturges,i,j;
    float anch_clase;
    float dato_inicial;
    if(respuesta=="2"){
        cout<<"Introducir el dato inicial: "<<endl;
        cin>>dato_inicial;
        //
        //longitud de alcance, ancho de clase, regla de sturges
        //
        cout<<"Introducir la longitud de alcance"<<endl;
        cin>>lon_alc;
        cout<<"Introducir la regla de sturges"<<endl;
        cin>>sturges;
        cout<<"La tabla tiene ancho de clase fijo? y/n"<<endl;
        cin>>respuesta;
        if(respuesta=="y"){
            cout<<"Introducir el ancho de clase"<<endl;
            cin>>anch_clase;
            for(i=0;i<sturges;i++){
                ancl[i]=anch_clase;
            }
        }else{
            cout<<"Introducir los diferentes anchos de clase"<<endl;
            for(i=0;i<sturges;i++){
                cout<<"Ancho de clase "<<i+1<<":  ";
                cin>>ancl[i];
            }
            cout<<endl;
        }
        respuesta="2";
    }else{
        //
        //introducción de los datos
        //
        cout<<endl<<"Introducir los datos:"<<endl;
        for (int i=0;i<cant_datos;i++){
            cin>>datos1[i];
        }
        //
        //ordenar los datos
        //
        /*Algoritmo burbuja*/
        for (i=0;i<cant_datos;i++){
            for (j=i+1;j<cant_datos;j++){
                if(datos1[i]>datos1[j]){
                    /*aux=datos1[i];
                    datos1[i]=datos1[j];
                    datos1[j]=aux;*/
                    swap(datos1[i],datos1[j]);
                }
            }
        }
        dato_inicial=datos1[0];
        //
        //mostrar datos ordenados
        //
        cout<<endl<<"Los datos ordenados:"<<endl;
        int k=1;
        for (int i=0;i<cant_datos;i++){
            if(k<=10){
                cout<<datos1[i]<<"   ";
                k++;
            }else{
                cout<<endl<<datos1[i]<<"   ";
                k=2;
            }
        }
        cout<<endl<<endl;
        //
        //longitud de alcance, ancho de clase, regla de sturges
        //
        cout<<"Desea introducir la longitud de alcance, la regla de sturges y el ancho de clase usted mismo? si/no"<<endl;
        cin>>respuesta;
        if (respuesta=="si"){
            cout<<"Introducir la longitud de alcance"<<endl;
            cin>>lon_alc;
            cout<<"Introducir la regla de sturges"<<endl;
            cin>>sturges;
            cout<<"Introducir el ancho de clase"<<endl;
            cin>>anch_clase;
            for(i=0;i<sturges;i++){
                ancl[i]=anch_clase;
            }
        }else{
        //
        //Longitud de alcance
        //
        lon_alc = datos1[cant_datos-1]-datos1[0];
        //
        //Regla de sturges
        //
        float aux2,aux3;
        aux3 = 1+3.3*log10(cant_datos);
        for(i=1;i<=aux3+1;i++){
            if(i>aux3){
                aux2=i-aux3;
                if (aux2>0.5){
                    aux3=i-1;
                    break;
                }else{
                    aux3=i;
                    break;
                }
            }
        }
        sturges=aux3;
        //
        //Ancho de clase
        //
        anch_clase = lon_alc/sturges;
        for(i=1;i<=anch_clase+1;i++){
            if(i>anch_clase){
                anch_clase=i;
                break;
            }if (i==anch_clase){
                anch_clase=i;
                break;
            }
        }
        for(i=0;i<sturges;i++){
            ancl[i]=anch_clase;
        }
        cout<<"Longitud de alcance: "<<lon_alc<<endl;
        cout<<"Regla de sturges:    "<<sturges<<endl;
        cout<<"Ancho de clase:      "<<anch_clase<<endl;
        respuesta="1";
        }
    }
    //
    //tabla de frecuencias
    //
    cout<<endl;
    cout<<"         T  A  B  L  A      D  E      F  R  E  C  U  E  N  C  I  A  S"<<endl;
    cout<<endl;
    cout<<"   Intervalo   |   Marcas   |  Frecuencia  |  Frec Abs   |  Frecuencia  |  Frec Relat  |  Frec Relat  | Frec Abs acum"<<endl;
    cout<<"    o clase    |  de clase  |   absoluta   |  acumulada  |   relativa   |  acumulada   |  porcentual  |   mayor que  "<<endl;
    cout<<"      Ii       |     xi     |      fi      |      Fi     |      hi      |      Hi      |     hi %     |      Fi *    "<<endl;
    cout<<endl;
    float xi[sturges];
    float fi[sturges];
    float Fi[sturges];
    float control=0;
    j=0;
    float frec_abs_acum=0;
    float frec_rel_acum=0;
    float frec_abs_mayor=cant_datos;
    for (i=0;i<sturges;i++){
        if (respuesta=="2"){
            //
            //  Intervalos y marcas de clase
            //
            datos[i]=dato_inicial+control;
            cout<<"     "<<datos[i]<<"-";
            control=control+ancl[i];
            datos[i+1]=dato_inicial+control;
            cout<<datos[i+1]<<"    |";
            xi[i]=(datos[i]+datos[i+1])/2;
            cout<<"     "<<xi[i]<<"     |      ";
            //
            //Frecuencia absoluta
            //
            cin>>fi[i];
            cout<<"                                   //       |";
        }else{
            //
            //Intervalos y marcas de clase
            //
            datos[i]=dato_inicial+control;
            cout<<"     "<<datos[i]<<"-";
            control=control+ancl[i];
            datos[i+1]=dato_inicial+control;
            cout<<datos[i+1]<<"    |";
            xi[i]=(datos[i]+datos[i+1])/2;
            cout<<"     "<<xi[i]<<"     |";
            //
            //Frecuencia absoluta
            //
            float frec_abs=0;
            while(j<=cant_datos){
                if(datos1[j]<=(datos1[0]+control-0.00001)&&i<sturges-1){
                    frec_abs++;
                }
                if(datos1[j]>(datos1[0]+control-0.00001)&&i<sturges-1){
                    if(i<sturges-1){
                        fi[i]=frec_abs;
                        break;
                    }
                }
                if(i==sturges-1){
                    frec_abs++;
                }
                if(j==cant_datos){
                    fi[i]=frec_abs-1;
                break;
                }
                j++;
            }
            cout<<"      "<<fi[i]<<"       |";
        }
        //
        //Frecuencia absoluta acumulada
        //
        frec_abs_acum=frec_abs_acum+fi[i];
        Fi[i]=frec_abs_acum;
        cout<<"      "<<Fi[i]<<"     |";
        //
        //Frecuencia Relativa
        //
        float hi[sturges];
        float frec_rel=fi[i]/cant_datos;
        hi[i]=roundf(frec_rel*100)/100;
        cout<<"      "<<hi[i]<<"    |";
        //
        //Frecuencia relativa acumulada
        //
        float Hi[sturges];
        frec_rel_acum=frec_rel_acum+hi[i];
        Hi[i]=frec_rel_acum;
        cout<<"      "<<Hi[i]<<"    |";
        //
        //Frecuencia relativa porcentual
        //
        float hip[sturges];
        float frec_rel_por=hi[i]*100;
        hip[i]=frec_rel_por;
        cout<<"      "<<hip[i]<<"%     |";
        //
        //Frecuencia absoluta acumulada mayor que
        //
        float fip[sturges];
        fip[i]=frec_abs_mayor;
        cout<<"      "<<fip[i]<<endl;
        frec_abs_mayor=frec_abs_mayor-fi[i];
    }
    cout<<endl<<endl<<endl<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    //
    /*          MEDIA               MEDIANA                 MODA            */
    //
    //  M   E   D   I   A
    //
    float media[sturges];
    float media_suma=0;
    cout<<endl;
    cout<<"                 M E D I A"<<endl;
    cout<<"|     xi     |      fi      |    xi * fi"<<endl;
    for (i=0;i<sturges;i++){
        media[i]=xi[i]*fi[i];
        media_suma=media_suma+media[i];
        cout<<"|     "<<xi[i]<<"     |      "<<fi[i]<<"      |      "<<media[i]<<endl;
    }
    cout<<"                           Suma: "<<media_suma<<endl;
    cout<<"   _"<<endl;
    cout<<"   X = Ei=1  xi*fi  =   "<<media_suma;
    media_suma=media_suma/cant_datos;
    media_suma=roundf(media_suma*100)/100;
    cout<<"  =  "<<media_suma<<endl;
    cout<<"             n           "<<cant_datos<<endl<<endl;
    cout<<endl<<"MEDIA: "<<media_suma<<endl<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    int posicion;
    //
    //  M   E   D   I   A   N   A
    //
    float mediana;
    if (cant_datos%2==0){
        posicion=cant_datos/2;
    }else{
        posicion=(cant_datos+1)/2;
    }
    for (i=0;i<sturges;i++){
        if (posicion==Fi[i]){
            mediana=datos[i+1];
            break;
        }if(i==0){
            if (posicion>0){
                if (posicion<Fi[i+1]){
                mediana=(datos[i+1])+((posicion-Fi[i])/fi[i+1])*ancl[i+1];
                break;
                }
            }
        }else{
            if (posicion>Fi[i-1]){
                if (posicion<Fi[i+1]){
                mediana=(datos[i+1])+((posicion-Fi[i])/fi[i+1])*ancl[i+1];
                break;
                }
            }
        }
    }
    mediana=roundf(mediana*100)/100;
    cout<<"La mediana se encuentra en el intervalo: "<<i+2<<endl<<endl;
    cout<<"      Me = Li + (n/2) - Fi-1 . Ai = "<<datos[i+1]<<" + "<<posicion<<" - "<<Fi[i]<<" . "<<ancl[i+1]<<" = "<<mediana<<endl;
    cout<<"                      fi                    "<<fi[i+1]<<endl<<endl;
    cout<<"MEDIANA: "<<mediana<<endl<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    //  M   O   D   A
    int mayor=0;
    float moda;
    for (i=0;i<sturges;i++){
        if(fi[i]>mayor){
            mayor=fi[i];
            posicion=i;
        }
    }
    moda=datos[posicion]+((fi[posicion]-fi[posicion-1])/((fi[posicion]-fi[posicion-1])+(fi[posicion]-fi[posicion+1])))*ancl[posicion];
    moda=roundf(moda*100)/100;
    cout<<endl<<"Frecuencia mayor: "<<mayor<<endl<<endl;
    cout<<"   Mo = Li + ________fi - fi-1______ . Ai = "<<datos[posicion]<<" + _____"<<fi[posicion]<<" - "<<fi[posicion-1]<<"_____ . "<<ancl[posicion]<<" = "<<moda<<endl;
    cout<<"             (fi - fi-1)+(fi - fi+1)             ("<<fi[posicion]<<" - "<<fi[posicion-1]<<")+("<<fi[posicion]<<" - "<<fi[posicion+1]<<")"<<endl<<endl;
    cout<<"La moda se encuentra en el intervalo: "<<posicion+1<<endl;
    cout<<"MODA: "<<moda<<endl<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    //
    //      E   S   T   A   D   I   G   R   A   F   O   S       D   E       D   I   S   P   E   R   S   I   O   N
    //
    cout<<endl;
    cout<<"Ahora calculare la:  Varianza                  V(x)"<<endl;
    cout<<"                     Desviacion Tipica         Sx  "<<endl;
    cout<<"                     Coeficiente de Variación  C.V."<<endl;
    cout<<endl;
    float Vx[sturges];
    float varianza=0;
    float desv_tip;
    float coef_vari;
    cout<<endl;
    cout<<"                 V A R I A N Z A"<<endl;
    cout<<"|     xi     |      fi      |    MEDIA (X)  | (xi - X)^2 * fi"<<endl;
    for (i=0;i<sturges;i++){
        Vx[i]=(pow((xi[i]-media_suma),2))*fi[i];
        Vx[i]=roundf(Vx[i]*100)/100;
        varianza=varianza+Vx[i];
        cout<<"|     "<<xi[i]<<"     |      "<<fi[i]<<"      |      "<<media_suma<<"     |     "<<Vx[i]<<endl;
    }
    cout<<"                                          Suma: "<<varianza<<endl;
    cout<<endl;
    cout<<"   V(x) = Ei=1  (xi - X)^2 * fi = "<<varianza;
    varianza=varianza/cant_datos;
    cout<<"  = "<<varianza<<endl;
    cout<<"                  n                "<<cant_datos<<endl<<endl;
    cout<<endl;
    cout<<"La Varianza es: "<<varianza<<endl;
    cout<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    desv_tip=sqrt(varianza);
    cout<<"    Sx = sqrt(varianza) = sqrt("<<varianza<<")  =  "<<desv_tip<<endl;
    cout<<endl;
    cout<<"La Desviacion Tipica es: "<<desv_tip<<endl;
    cout<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    coef_vari=(desv_tip/media_suma)*100;
    cout<<endl;
    cout<<"    C.V. =  Sx . 100%  =  "<<desv_tip<<" . 100%   =  "<<coef_vari<<"%"<<endl;
    cout<<"            X              "<<media_suma<<endl;
    cout<<endl;
    cout<<"La Coeficiente de Variacion es: "<<coef_vari<<"%"<<endl;
    cout<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    //
    //  O   T   R   A   S       M   E   D   I   D   A   S       D   E       D   I   S   P   E   R   S   I   O   N
    //
    //  Desviacion cuartilica
    //
    float pos;
    float desv_cuart;
    float cuar1, cuar3;
    pos = cant_datos2*1/4;
    cout<<endl;
    cout<<"   1 . n =  1 . "<<cant_datos<<" = "<<pos<<endl;
    cout<<"   4        4"<<endl;
    cout<<endl;
    for (i=0;i<sturges;i++){
        if (pos==Fi[i]){
            cuar1=datos[i+1];
            break;
        }if (i==0){
            if (pos>0){
                if (pos<Fi[i]){
                    cuar1=datos[i]+((pos-0)/fi[i])*ancl[i];
                    cout<<"      Q1 = Li + (n*3/4) - Fi-1 . Ai = "<<datos[i]<<" + "<<pos<<" - 0 . "<<ancl[i]<<" = "<<cuar1<<endl;
                    cout<<"                      fi                    "<<fi[i]<<endl<<endl;
                    break;
                }
            }
        }else{
            if (pos>Fi[i-1]){
                if (pos<Fi[i]){
                    cuar1=(datos[i])+((pos-Fi[i-1])/fi[i])*ancl[i];
                    cout<<"      Q1 = Li + (n*1/4) - Fi-1 . Ai = "<<datos[i]<<" + "<<pos<<" - "<<Fi[i-1]<<" . "<<ancl[i]<<" = "<<cuar1<<endl;
                    cout<<"                        fi                    "<<fi[i]<<endl<<endl;
                    break;
                }
            }
        }
    }
    pos = cant_datos2*3/4;
    cout<<endl;
    cout<<"   3 . n =  3 . "<<cant_datos<<" = "<<pos<<endl;
    cout<<"   4        4"<<endl;
    cout<<endl;
    for (i=0;i<sturges;i++){
        if (pos==Fi[i]){
            cuar3=datos[i+1];
            break;
        }if (i==0){
            if (pos>0){
                if (pos<Fi[i]){
                    cuar3=datos[i]+((pos-0)/fi[i])*ancl[i];
                    cout<<"      Q3 = Li + (n*3/4) - Fi-1 . Ai = "<<datos[i]<<" + "<<pos<<" - 0 . "<<ancl[i]<<" = "<<cuar3<<endl;
                    cout<<"                      fi                    "<<fi[i]<<endl<<endl;
                    break;
                }
            }
        }else{
            if (pos>Fi[i-1]){
                if (pos<Fi[i]){
                    cuar3=(datos[i])+((pos-Fi[i-1])/fi[i])*ancl[i];
                    cout<<"      Q3 = Li + (n*3/4) - Fi-1 . Ai = "<<datos[i]<<" + "<<pos<<" - "<<Fi[i-1]<<" . "<<ancl[i]<<" = "<<cuar3<<endl;
                    cout<<"                        fi                    "<<fi[i]<<endl<<endl;
                    break;
                }
            }
        }
    }
    desv_cuart=(cuar3-cuar1)/2;
    cout<<"cuartil 1: "<<cuar1<<endl;
    cout<<"cuartil 3: "<<cuar3<<endl;
    cout<<endl;
    cout<<"   Q = Q3 - Q1 =  "<<cuar3<<" - "<<cuar1<<"  =  "<<desv_cuart<<endl;
    cout<<"          2           2"<<endl;
    cout<<endl;
    cout<<"La desviacion cuartilica es: "<<desv_cuart<<endl<<endl;
    cout<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    //
    //  Desviación Media
    //
    float DM[sturges];
    float desv_media=0;
    cout<<"             D E S V I A C I O N     M E D I A     _"<<endl;
    cout<<"|     xi     |      fi      |    MEDIA (X)  |  |xi-X|*fi"<<endl;
    for (i=0;i<sturges;i++){
        DM[i]=(xi[i]-media_suma)*fi[i];
        if(DM[i]<0){
            DM[i]=DM[i]*(-1);
        }
        DM[i]=roundf(DM[i]*100)/100;
        desv_media=desv_media+DM[i];
        cout<<"|     "<<xi[i]<<"     |      "<<fi[i]<<"      |      "<<media_suma<<"     |     "<<DM[i]<<endl;
    }
    cout<<"                                         Suma: "<<desv_media<<endl;
    cout<<"                 _"<<endl;
    cout<<"  DM = Ei=1  |xi-X|*fi  =   "<<desv_media;
    desv_media=desv_media/cant_datos;
    cout<<"  =  "<<desv_media<<endl;
    cout<<"             n               "<<cant_datos<<endl<<endl;
    cout<<"La desviacion media es: "<<desv_media<<endl<<endl;
    cout<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"            "<<endl;
    //
    // M   E   D   I   D   A   S       D   E       A   S   I   M   E   T   R   I   A       Y       C   U    R   T   O   S   I   S
    //
    //  Coeficiente de Asimetria de Pearson
    //
    float coef_asim = ((3*(media_suma-mediana))/desv_tip);
    coef_asim=roundf(coef_asim*100)/100;
    cout<<"            _"<<endl;
    cout<<"     Pk = 3(X - Me) =  3("<<media_suma<<" - "<<mediana<<")  =  "<<coef_asim<<endl;
    cout<<"             Sx            "<<desv_tip<<endl<<endl;
    cout<<"El coeficiente de asimetria es: "<<coef_asim<<endl;
    if(coef_asim==0){
        cout<<"     "<<coef_asim<<" = 0"<<endl;
        cout<<"Entonces se dice que la distribucion es simetrica."<<endl<<endl;
    }if(coef_asim<0){
        cout<<"     "<<coef_asim<<" < 0"<<endl;
        cout<<"Entonces se dice que la distribucion es segada a la izquierda."<<endl<<endl;
    }if(coef_asim>0){
        cout<<"     "<<coef_asim<<" > 0"<<endl;
        cout<<"Entonces se dice que la distribucion es segada a la derecha."<<endl<<endl;
    }
    cout<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    //
    //  Coeficiente de Curtosis
    //
    float coef_curto;
    float perc10, perc90;
    pos = cant_datos2*10/100;
    cout<<endl;
    cout<<"   10 . n  =  10 . "<<cant_datos<<" = "<<pos<<endl;
    cout<<"  100        100"<<endl;
    cout<<endl;
    for (i=0;i<sturges;i++){
        if (pos==Fi[i]){
            perc10=datos[i+1];
            break;
        }
        if (i==0){
            if (pos>0){
                if (pos<Fi[i]){
                    perc10=datos[i]+((pos-0)/fi[i])*ancl[i];
                    cout<<"     P10 = Li + (n*10/100) - Fi-1 . Ai = "<<datos[i]<<" + "<<pos<<" - 0  . "<<ancl[i]<<" = "<<perc10<<endl;
                    cout<<"                         fi                    "<<fi[i]<<endl<<endl;
                    break;
                }
            }
        }else{
            if (pos>Fi[i-1]){
                if (pos<Fi[i]){
                    perc10=(datos[i])+((pos-Fi[i-1])/fi[i])*ancl[i];
                    cout<<"     P10 = Li + (n*10/100) - Fi-1 . Ai = "<<datos[i]<<" + "<<pos<<" - "<<Fi[i-1]<<" . "<<ancl[i]<<" = "<<perc10<<endl;
                    cout<<"                         fi                      "<<fi[i]<<endl<<endl;
                    break;
                }
            }
        }
    }
    pos = cant_datos2*90/100;
    cout<<endl;
    cout<<"   90 . n  =  90 . "<<cant_datos<<" = "<<pos<<endl;
    cout<<"  100        100"<<endl;
    cout<<endl;
    for (i=0;i<sturges;i++){
        if (pos==Fi[i]){
            perc90=datos[i+1];
            break;
        }
        if (i==0){
            if (pos>0){
                if (pos<Fi[i]){
                    perc90=datos[i]+((pos-0)/fi[i])*ancl[i];
                    cout<<"     P90 = Li + (n*90/100) - Fi-1 . Ai = "<<datos[i]<<" + "<<pos<<" - 0  . "<<ancl[i]<<" = "<<perc90<<endl;
                    cout<<"                         fi                      "<<fi[i]<<endl<<endl;
                    break;
                }
            }
        }else{
            if (pos>Fi[i-1]){
                if (pos<Fi[i]){
                    perc90=(datos[i])+((pos-Fi[i-1])/fi[i])*ancl[i];
                    cout<<"     P90 = Li + (n*90/100) - Fi-1 . Ai = "<<datos[i]<<" + "<<pos<<" - "<<Fi[i-1]<<" . "<<ancl[i]<<" = "<<perc90<<endl;
                    cout<<"                         fi                      "<<fi[i]<<endl<<endl;
                    break;
                }
            }
        }
    }
    coef_curto=(cuar3-cuar1)/(2*(perc90-perc10));
    coef_curto=roundf(coef_curto*1000)/1000;
    cout<<"cuartil 1: "<<cuar1<<endl;
    cout<<"cuartil 3: "<<cuar3<<endl;
    cout<<"percentil 10: "<<perc10<<endl;
    cout<<"percentil 90: "<<perc90<<endl;
    cout<<endl;
    cout<<"  Ck = ___Q3 - Q1___   =    "<<cuar3<<" - "<<cuar1<<"        =         "<<coef_curto<<endl;
    cout<<"       2*(P90 - P10)     2*("<<perc90<<" - "<<perc10<<")"<<endl;
    cout<<endl;
    cout<<endl<<"El coeficiente de curtosis es: "<<coef_curto<<endl<<endl;
    //
    //  C U A R T I L E S,      D E C I L E S,       P E R C E N T I L E S
    //
    float calcular_dato;
    int tipo_dato;
    respuesta="y";
    cout<<endl<<endl<<endl;
    cout<<"*********************************************************************************"<<endl;
    cout<<"*********************************************************************************"<<endl;
    cout<<"***                                                                           ***"<<endl;
    cout<<"***   Que estadigrafo de posicion desea calcular ahora?:                      ***"<<endl;
    cout<<"***                                                                           ***"<<endl;
    cout<<"***          1. Cuartil                                                       ***"<<endl;
    cout<<"***          2. Decil                                                         ***"<<endl;
    cout<<"***          3. Percentil                                                     ***"<<endl;
    cout<<"***          4. Ninguno                                                       ***"<<endl;
    cout<<"***                                                                           ***"<<endl;
    cout<<"*********************************************************************************"<<endl;
    cout<<"*********************************************************************************"<<endl;
    cout<<endl<<endl;
    cin>>tipo_dato;
    while (tipo_dato<4){
        if(tipo_dato==1){
            cout<<endl<<"Que cuartil debo de calcular? (0 < x < 4)  0 = Salir"<<endl;
            cin>>calcular_dato;
            cout<<endl;
            while (calcular_dato>0){
                pos = cant_datos2*calcular_dato/4;
                cout<<endl;
                cout<<"   "<<calcular_dato<<" . n  =  "<<calcular_dato<<" . "<<cant_datos<<" = "<<pos<<endl;
                cout<<"   4         4"<<endl;
                cout<<endl;
                float cuartil;
                for (i=0;i<sturges;i++){
                    if (pos==Fi[i]){
                        cuartil=datos[i+1];
                        break;
                    }if(i==0){
                        if (pos>0){
                            if (pos<Fi[i]){
                                cuartil=(datos[i])+((pos-0)/fi[i])*ancl[i];
                                cout<<endl;
                                cout<<"     Q"<<calcular_dato<<" = Li + (n*"<<calcular_dato<<"/4) - Fi-1 . Ai = "<<datos[i]<<" + "<<pos<<" - 0 . "<<ancl[i]<<" = "<<cuartil<<endl;
                                cout<<"                         fi                      "<<fi[i]<<endl;
                                cout<<endl;
                                break;
                            }
                        }
                    }else{
                        if (pos>Fi[i-1]){
                            if (pos<Fi[i]){
                                cuartil=(datos[i])+((pos-Fi[i-1])/fi[i])*ancl[i];
                                cout<<endl;
                                cout<<"     Q"<<calcular_dato<<" = Li + (n*"<<calcular_dato<<"/4) - Fi-1 . Ai = "<<datos[i]<<" + "<<pos<<" - "<<Fi[i-1]<<" . "<<ancl[i]<<" = "<<cuartil<<endl;
                                cout<<"                      fi                    "<<fi[i]<<endl;
                                cout<<endl;
                                break;
                            }
                        }
                    }
                }
                cout<<"El cuartil "<<calcular_dato<<" es: "<<cuartil<<endl<<endl;
                cout<<endl<<"Que otro cuartil debo de calcular? (0 < x < 4)  0 = Salir"<<endl;
                cin>>calcular_dato;
            }
        } if(tipo_dato==2){
            cout<<endl<<"Que decil debo de calcular? (0 < x < 10)  0 = Salir"<<endl;
            cin>>calcular_dato;
            cout<<endl;
            while (calcular_dato>0){
                pos = cant_datos2*calcular_dato/10;
                cout<<endl;
                cout<<"   "<<calcular_dato<<" . n  =  "<<calcular_dato<<" . "<<cant_datos<<" = "<<pos<<endl;
                cout<<"   10        10"<<endl;
                cout<<endl;
                float decil;
                for (i=0;i<sturges;i++){
                    if (pos==Fi[i]){
                        decil=datos[i+1];
                        break;
                    }if(i==0){
                        if (pos>0){
                            if (pos<Fi[i]){
                                decil=(datos[i])+((pos-0)/fi[i])*ancl[i];
                                cout<<endl;
                                cout<<"     D"<<calcular_dato<<" = Li + (n*"<<calcular_dato<<"/4) - Fi-1 . Ai = "<<datos[i]<<" + "<<pos<<" - 0 . "<<ancl[i]<<" = "<<decil<<endl;
                                cout<<"                      fi                    "<<fi[i]<<endl;
                                cout<<endl;
                                break;
                            }
                        }
                    }else{
                        if (pos>Fi[i-1]){
                            if (pos<Fi[i]){
                                decil=(datos[i])+((pos-Fi[i-1])/fi[i])*ancl[i];
                                cout<<endl;
                                cout<<"     D"<<calcular_dato<<" = Li + (n*"<<calcular_dato<<"/4) - Fi-1 . Ai = "<<datos[i]<<" + "<<pos<<" - "<<Fi[i-1]<<" . "<<ancl[i]<<" = "<<decil<<endl;
                                cout<<"                      fi                    "<<fi[i]<<endl;
                                cout<<endl;
                                break;
                            }
                        }
                    }
                }
                cout<<"El decil "<<calcular_dato<<" es: "<<decil<<endl<<endl;
                cout<<endl<<"Que otro decil debo de calcular? (0 < x < 10)  0 = Salir"<<endl;
                cin>>calcular_dato;
            }
        } if(tipo_dato==3){
            cout<<endl<<"Que percentil debo de calcular? (0 < x < 100)  0 = Salir"<<endl;
            cin>>calcular_dato;
            cout<<endl;
            while (calcular_dato>0){
                pos = cant_datos2*calcular_dato/100;
                cout<<endl;
                cout<<"    "<<calcular_dato<<" . n   =   "<<calcular_dato<<" . "<<cant_datos<<" = "<<pos<<endl;
                cout<<"   100        100"<<endl;
                cout<<endl;
                float percentil;
                for (i=0;i<sturges;i++){
                    if (pos==Fi[i]){
                        percentil=datos[i+1];
                        break;
                    }if(i==0){
                        if (pos>0){
                            if (pos<Fi[i]){
                                percentil=(datos[i])+((pos-0)/fi[i])*ancl[i];
                                cout<<endl;
                                cout<<"     P"<<calcular_dato<<" = Li + (n*"<<calcular_dato<<"/4) - Fi-1 . Ai = "<<datos[i]<<" + "<<pos<<" - 0 . "<<ancl[i]<<" = "<<percentil<<endl;
                                cout<<"                      fi                    "<<fi[i]<<endl;
                                cout<<endl;
                                break;
                            }
                        }
                    }else{
                        if (pos>Fi[i-1]){
                            if (pos<Fi[i]){
                                percentil=(datos[i])+((pos-Fi[i-1])/fi[i])*ancl[i];
                                cout<<endl;
                                cout<<"     P"<<calcular_dato<<" = Li + (n*"<<calcular_dato<<"/4) - Fi-1 . Ai = "<<datos[i]<<" + "<<pos<<" - "<<Fi[i-1]<<" . "<<ancl[i]<<" = "<<percentil<<endl;
                                cout<<"                      fi                    "<<fi[i]<<endl;
                                cout<<endl;
                                break;
                            }
                        }
                    }
                }
                cout<<"El percentil "<<calcular_dato<<" es: "<<percentil<<endl<<endl;
                cout<<endl<<"Que otro percentil debo de calcular? (0 < x < 100)  0 = Salir"<<endl;
                cin>>calcular_dato;
            }
        }
        cout<<endl;
        cout<<"Desea calcular otro tipo de estadigrafo de posicion?:"<<endl;
        cout<<"     1.Cuatil   2.Decil   3.Percentil   4.Ninguno"<<endl;
        cout<<endl;
        cin>>tipo_dato;
        cout<<endl;
    }
    cout<<"Fin del programa, hasta luego."<<endl<<endl<<endl;
    return 0;
}
