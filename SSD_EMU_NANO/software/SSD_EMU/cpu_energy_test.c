#if RUN_CPU_ENERGY_TESTS
	printf("FIR\n");
	int z = 0;
	for (z = 0; z < 1000; z = z + 1)
	{
		printf("%i:\t", z);
		res_fir = fir_testbench();
		measure_power();
		printf("\t%i\n", res_fir);
		alt_timestamp_start();
	}
	printf("DES\n");
	for(z = 0; z < 1000; z = z + 1)
	{
		printf("%i:\t", z);
		res_des = des_testbench();
		measure_power();
		printf("\t%i\n", res_des);
		alt_timestamp_start();
	}
	printf("CI\n");
	for (z = 0; z < 1000; z = z + 1)
	{
		printf("%i:\t", z);
		res_ci = ci_testbench();
		measure_power();
		printf("\t%i\n", res_ci);
		alt_timestamp_start();
	}
	printf("AES\n");
	for(z = 0; z < 1000; z = z + 1)
	{
		printf("%i:\t", z);
		res_aes = aes_testbench();
		measure_power();
		printf("\t%i\n", res_aes);
		alt_timestamp_start();
	}
#endif
