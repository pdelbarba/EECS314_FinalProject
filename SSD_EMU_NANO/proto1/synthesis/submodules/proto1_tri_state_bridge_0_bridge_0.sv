// (C) 2001-2012 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.


// $Id: //acds/rel/12.0/ip/merlin/altera_tristate_conduit_bridge/altera_tristate_conduit_bridge.sv.terp#1 $
// $Revision: #1 $
// $Date: 2012/02/13 $
// $Author: swbranch $

//Defined Terp Parameters


			    

`timescale 1 ns / 1 ns
  				      
module proto1_tri_state_bridge_0_bridge_0 (
     input  logic clk
    ,input  logic reset
    ,input  logic request
    ,output logic grant
    ,input  logic[ 25 :0 ] tcs_address_to_the_cfi_flash_0
    ,output  wire [ 25 :0 ] address_to_the_cfi_flash_0
    ,input  logic[ 0 :0 ] tcs_write_n_to_the_cfi_flash_0
    ,output  wire [ 0 :0 ] write_n_to_the_cfi_flash_0
    ,output logic[ 15 :0 ] tcs_data_to_and_from_the_cfi_flash_0_in
    ,input  logic[ 15 :0 ] tcs_data_to_and_from_the_cfi_flash_0
    ,input  logic tcs_data_to_and_from_the_cfi_flash_0_outen
    ,inout  wire [ 15 :0 ]  data_to_and_from_the_cfi_flash_0
    ,input  logic[ 0 :0 ] tcs_read_n_to_the_cfi_flash_0
    ,output  wire [ 0 :0 ] read_n_to_the_cfi_flash_0
    ,input  logic[ 0 :0 ] tcs_select_n_to_the_cfi_flash_0
    ,output  wire [ 0 :0 ] select_n_to_the_cfi_flash_0
		     
   );
   reg grant_reg;
   assign grant = grant_reg;
   
   always@(posedge clk) begin
      if(reset)
	grant_reg <= 0;
      else
	grant_reg <= request;      
   end
   


 // ** Output Pin address_to_the_cfi_flash_0 
 
    reg                       address_to_the_cfi_flash_0en_reg;     
  
    always@(posedge clk) begin
	 if( reset ) begin
	   address_to_the_cfi_flash_0en_reg <= 'b0;
	 end
	 else begin
	   address_to_the_cfi_flash_0en_reg <= 'b1;
	 end
     end		     
   
 
    reg [ 25 : 0 ] address_to_the_cfi_flash_0_reg;   

     always@(posedge clk) begin
	 address_to_the_cfi_flash_0_reg   <= tcs_address_to_the_cfi_flash_0[ 25 : 0 ];
      end
          
 
    assign 	address_to_the_cfi_flash_0[ 25 : 0 ] = address_to_the_cfi_flash_0en_reg ? address_to_the_cfi_flash_0_reg : 'z ;
        


 // ** Output Pin write_n_to_the_cfi_flash_0 
 
    reg                       write_n_to_the_cfi_flash_0en_reg;     
  
    always@(posedge clk) begin
	 if( reset ) begin
	   write_n_to_the_cfi_flash_0en_reg <= 'b0;
	 end
	 else begin
	   write_n_to_the_cfi_flash_0en_reg <= 'b1;
	 end
     end		     
   
 
    reg [ 0 : 0 ] write_n_to_the_cfi_flash_0_reg;   

     always@(posedge clk) begin
	 write_n_to_the_cfi_flash_0_reg   <= tcs_write_n_to_the_cfi_flash_0[ 0 : 0 ];
      end
          
 
    assign 	write_n_to_the_cfi_flash_0[ 0 : 0 ] = write_n_to_the_cfi_flash_0en_reg ? write_n_to_the_cfi_flash_0_reg : 'z ;
        


 // ** Bidirectional Pin data_to_and_from_the_cfi_flash_0 
   
    reg                       data_to_and_from_the_cfi_flash_0_outen_reg;
  
    always@(posedge clk) begin
	 data_to_and_from_the_cfi_flash_0_outen_reg <= tcs_data_to_and_from_the_cfi_flash_0_outen;
     end
  
  
    reg [ 15 : 0 ] data_to_and_from_the_cfi_flash_0_reg;   

     always@(posedge clk) begin
	 data_to_and_from_the_cfi_flash_0_reg   <= tcs_data_to_and_from_the_cfi_flash_0[ 15 : 0 ];
      end
         
  
    assign 	data_to_and_from_the_cfi_flash_0[ 15 : 0 ] = data_to_and_from_the_cfi_flash_0_outen_reg ? data_to_and_from_the_cfi_flash_0_reg : 'z ;
       
  
    reg [ 15 : 0 ] 	data_to_and_from_the_cfi_flash_0_in_reg;
								    
    always@(posedge clk) begin
	 data_to_and_from_the_cfi_flash_0_in_reg <= data_to_and_from_the_cfi_flash_0[ 15 : 0 ];
    end
    
  
    assign      tcs_data_to_and_from_the_cfi_flash_0_in[ 15 : 0 ] = data_to_and_from_the_cfi_flash_0_in_reg[ 15 : 0 ];
        


 // ** Output Pin read_n_to_the_cfi_flash_0 
 
    reg                       read_n_to_the_cfi_flash_0en_reg;     
  
    always@(posedge clk) begin
	 if( reset ) begin
	   read_n_to_the_cfi_flash_0en_reg <= 'b0;
	 end
	 else begin
	   read_n_to_the_cfi_flash_0en_reg <= 'b1;
	 end
     end		     
   
 
    reg [ 0 : 0 ] read_n_to_the_cfi_flash_0_reg;   

     always@(posedge clk) begin
	 read_n_to_the_cfi_flash_0_reg   <= tcs_read_n_to_the_cfi_flash_0[ 0 : 0 ];
      end
          
 
    assign 	read_n_to_the_cfi_flash_0[ 0 : 0 ] = read_n_to_the_cfi_flash_0en_reg ? read_n_to_the_cfi_flash_0_reg : 'z ;
        


 // ** Output Pin select_n_to_the_cfi_flash_0 
 
    reg                       select_n_to_the_cfi_flash_0en_reg;     
  
    always@(posedge clk) begin
	 if( reset ) begin
	   select_n_to_the_cfi_flash_0en_reg <= 'b0;
	 end
	 else begin
	   select_n_to_the_cfi_flash_0en_reg <= 'b1;
	 end
     end		     
   
 
    reg [ 0 : 0 ] select_n_to_the_cfi_flash_0_reg;   

     always@(posedge clk) begin
	 select_n_to_the_cfi_flash_0_reg   <= tcs_select_n_to_the_cfi_flash_0[ 0 : 0 ];
      end
          
 
    assign 	select_n_to_the_cfi_flash_0[ 0 : 0 ] = select_n_to_the_cfi_flash_0en_reg ? select_n_to_the_cfi_flash_0_reg : 'z ;
        

endmodule


