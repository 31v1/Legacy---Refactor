Algoritmo Factura
	Definir MontoPorConsumo, PorcentajeCruzR, ImpuestoCruzRoja, ImpuestoRenta, ImpuestoIVA, MontoFactura Como Real;
	Definir NumeroAbonado, MontoFIJOServicio, CantidadWatts, DifWATTS, Contador como entero;
	Definir NombreCliente como cadena;
	Definir continuar como caracter;
	Definir acumm, acummCNFL, acummKWVs, acummFIJO, acummCroja, acummConsumo, acummIVA como real;
	NombreCliente="X";
	NumeroAbonado=0;
	MontoFIJOServicio=5400;
	MontoPorConsumo=0;
	CantidadWatts=0;
	PorcentajeCruzR=10;
	ImpuestoCruzRoja=0; 
	MontoFactura=0;
	ImpuestoIVA=0;
	ImpuestoRenta=0;
	continuar= 's';
	Contador=0;
	acumm=0;
	acummCNFL=0;
	DifWATTS=0;
	acummKWVs=0;
	acummFIJO=0;
	acummCroja=0;
	acummIVA=0;
	acummConsumo=0;
	
	Mientras continuar="s" o continuar= "S" hacer
		Escribir "Ingrese el nombre del abonado";
		Leer NombreCliente;
		Escribir "Ingrese el número de abonado";
		Repetir
			Leer NumeroAbonado;
			Si NumeroAbonado<=0 entonces
				Escribir "Error! El número de abonado no puede ser 0";
				Escribir "Ingrese el número de abonado";
			FinSi
		Hasta Que NumeroAbonado>0;
		Escribir "Ingrese la cantidad de Kilo Wats consumidos";
		Repetir
			Leer CantidadWatts;	
			Si CantidadWatts<=0 entonces
				Escribir "ERROR! La cantidad de Kilo Wats no puede ser cero";
				Escribir "Ingrese la cantidad de Kilo Wats consumidos";
			FinSi
		Hasta Que CantidadWatts>0;		
		Si (CantidadWatts<=15) Entonces
			MontoPorConsumo=CantidadWatts*500;
		SiNo
			Si(CantidadWatts>15) y (CantidadWatts<=30) entonces
				DifWATTS=CantidadWatts-15;
				MontoPorConsumo=(15*500)+(DifWATTS*550);
			Sino
				Si(CantidadWatts>31) Entonces;
					DifWATTS=CantidadWatts-30;
					MontoPorConsumo=(15*500)+(15*550)+(DifWATTS*600);
					Finsi
			FinSi
		FinSi
		Si (CantidadWatts>25) Entonces
			ImpuestoIVA=(CantidadWatts*0.13);
		SiNo
			ImpuestoIVA=0;
		FinSi
		
		ImpuestoCruzRoja=PorcentajeCruzR*CantidadWatts;
		ImpuestoRenta= ((MontoPorConsumo+MontoFIJOservicio)*0.10);
		MontoFactura= MontoFIJOServicio+MontoPorConsumo+ImpuestoCruzRoja+ImpuestoIVA;
		
		
		Escribir "Factura Servicio de Electricidad Compañia Nacional de Fuerza y Luz."; 
		Escribir  "  ";
		Escribir "Nombre: ", NombreCliente, ".";
		Escribir "Número de abonado: ", NumeroAbonado, ".";
		Escribir  "  ";
		Escribir "Cantidad Kilo Watts consumidos: ", CantidadWatts,".";
		Escribir "Monto fijo por servicio: ", MontoFIJOservicio,".";
		Escribir "Monto por Consumo: ", MontoPorConsumo,".";
		Escribir "Impuesto Cruz roja: ", ImpuestoCruzRoja,".";
		Escribir "Impuesto del IVA: ", ImpuestoIVA,".";
		Escribir "Total a cancelar: ", MontoFactura,".";
		Escribir  "  ";
		Contador=Contador+1;
		acumm=acumm+MontoFactura;
		acummCNFL= acummCNFL+ImpuestoRenta;
		acummKWVs= acummKWVs+CantidadWatts;
		acummFIJO= acummFIJO+MontoFIJOservicio;
		acummConsumo= acummConsumo+MontoPorConsumo;
		acummCroja= acummCroja+ImpuestoCruzRoja;
		acummIVA= acummIVA+ImpuestoIVA;
		Escribir "     *Ultima linea*";
		Escribir  "  ";
		Escribir "¿Desea continuar? s= si, n=no";
		Leer continuar;
		Escribir  "  ";
	FinMientras
	
	Escribir "            Informe Final";
	Escribir  "  ";
	Escribir "         Clientes procesados: ", Contador ;
	Escribir "         Cantidad total de KWVs consumidos por todos los abonados: ",acummKWVs;
	Escribir "         Monto total por servicio fijo: ",acummFIJO;
	Escribir "         Monto total por consumo: ",acummConsumo;
	Escribir "         Monto Total ley Cruz Roja ", acummCroja;
	Escribir "         Monto total IVA: ", acummIVA;
	Escribir "         Monto total de las facturas ",acumm;
	Escribir "         Monto de impuesto de la renta CNFL a gobierno ", acummCNFL;
	Escribir  "  ";
	Escribir "     *Ultima linea*";
	
FinAlgoritmo
