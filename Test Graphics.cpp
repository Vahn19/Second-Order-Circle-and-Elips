#include<graphics.h>
#include<dos.h>
#include<windows.h>

void drawcircle(int xp,int yp, int r, int clr, int thickness)
{
	int i;
	for(i=0;i<thickness;i++)
	{
	int x=0;
	int y=r;
	int d=1-r;
	int dr = 3;
	int ddr = -2*r+5;
	  do
	  {
	  	putpixel(xp+x,yp+y,clr);
	  	putpixel(xp+y,yp+x,clr);
	  	putpixel(xp-x,yp+y,clr);
	  	putpixel(xp-y,yp+x,clr);
	  	putpixel(xp-x,yp-y,clr);  
	  	putpixel(xp-y,yp-x,clr);
	  	putpixel(xp+y,yp-x,clr);   
	  	putpixel(xp+x,yp-y,clr);
	  	
	  	
	  	if(d <0)
	  	{
	  		d += dr;
	  		dr += 2;
	  		ddr+= 2;
		  }
		else
		{
			d += ddr;
			dr += 2;
			ddr += 4;
			y -= 1;
		}
		x=x+1;
	  }while(x<y);
	  r++;
	}
}

void drawelipse(int xp,int yp, int a, int b, int clr, int thickness)
{
	int i=0;
	for(i=0;i<thickness;i++)
	{
		int x=0;
		int y=b;
		int a2 = a*a;
		int b2 = b*b;
		int d=b2*(x+1)*(x+1)+a2*(y*y-y)-a2*b2;
		int dd;
		int ddr = b2*(2*x+3) + a2*(2-2*y);
		int dr = b2*(2*x+3);
		
		do
		{
			putpixel(xp+x,yp-y,clr);
			putpixel(xp-x,yp+y,clr);
			putpixel(xp+x,yp+y,clr);
			putpixel(xp-x,yp-y,clr);
			
			
			if(d<0)
			{
				d += dr;
				dr += 2*b2;
				ddr += 2*b2; 
			}
			else
			{
				y -= 1;
				d += ddr;
				dr += 2*b2;
				ddr += (2*b2 + 2*a2);
			}
			x += 1;
		}
		while((2*x*b2)<(2*y*a2));
		
		d=b2*(x*x+x)+a2*(y-1)*(y-1)-a2*b2;
		dd = a2*(3-2*y);
		ddr = b2*(2*x+2) + a2*(3-2*y);
		
		do
		{
			putpixel(xp+x,yp-y,clr);
			putpixel(xp-x,yp+y,clr);
			putpixel(xp+x,yp+y,clr);
			putpixel(xp-x,yp-y,clr);
			
			if(d>0)
			{
				d += dd;
				dd += 2*a2;
				ddr += 2*a2;
			}	
			else
			{
				x += 1;
				d += ddr;
				dd += (2*a2);
				ddr += (2*b2 + 2*a2);
			}
			y -= 1;
		}
		while(y>=0);
		a++;
		b++;
	}
}

void menu()
{
   printf("1. Draw a Circle\n");
   printf("2. Draw an Elipse\n");
   printf("3. Clear Screen\n");
   printf("4. Refresh Screen\n");
   printf("5. Edit circle\n");
   printf("6. Edit Elipse\n");
   printf("7. Exit\n");
}

main()
{
   int input, c_cnt=0, e_cnt=0, c_input, c_edit, c_subedit, e_input, e_edit, e_subedit,i,temp;
   int xc[20],yc[20],r[20],c_clr[20],c_thick[20];
   int xe[20],ye[20],d1[20],d2[20],e_clr[20],e_thick[20];
   bool c_stats[20]={false};
   bool e_stats[20]={false};
   char color[15][20]={"blue","green","cyan","red","magenta","brown","lightgray","darkgray","lightblue","lightgreen","lightcyan","lightred","lightmagenta","yellow","white"};
   
   printf("WELCOME TO OUR PROGRAM\n");
   system("pause");
   system("cls");
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");
   //int gd = DETECT, gm;
   //initgraph(&gd, &gm, "");
   //int h = GetSystemMetrics(SM_CYSCREEN);
   //int w = GetSystemMetrics(SM_CXSCREEN);
   //initwindow(w,h,"");

  while(input!=7)
  {
   menu();
   printf("Please input number: ");
   scanf("%d", &input);
   system("cls");
	switch(input){
	   case 1:
		   	printf("Insert the coordinate of X-axis: ");
		   	scanf("%d", &xc[c_cnt]);
		   	printf("\nInsert the coordinate of y-axis: ");
		   	scanf("%d", &yc[c_cnt]);
		   	printf("\nInsert the radius: ");
		   	scanf("%d", &r[c_cnt]);
		   		for(i=0;i<15;i++)
				{
					printf("\n %d = %s",i+1,color[i]);
				}
		   		printf("\nInsert the color of the circle: ");
ccolor_error:	scanf("%d", &c_clr[c_cnt]);
			   	if(c_clr[c_cnt]<1 || c_clr[c_cnt]>15)
			   	{
			   		printf("\nPlease insert color between 1-15: ")	;
			   		goto ccolor_error;
				}
				else
				{
					printf("\nPlease insert the thickness of the circle: ");
cthickness_error:	scanf("%d", &c_thick[c_cnt]);
					if(c_thick[c_cnt]<1)
					{
						printf("Please input more than 0: ");
						goto cthickness_error;
					}
					else
					{
				   	drawcircle(xc[c_cnt],yc[c_cnt],r[c_cnt],c_clr[c_cnt],c_thick[c_cnt]);
				   	c_stats[c_cnt] = true;
				   	c_cnt++;
				    }
			    }
	   break;
	   case 2:
	   		printf("Insert the coordinate of X-axis: ");
		   	scanf("%d", &xe[e_cnt]);
		   	printf("\nInsert the coordinate of y-axis: ");
		   	scanf("%d", &ye[e_cnt]);
		   	printf("\nInsert the first diagonal: ");
		   	scanf("%d", &d1[e_cnt]);
		   	printf("\nInsert the second diagonal: ");
		   	scanf("%d", &d2[e_cnt]);
		   		for(i=0;i<15;i++)
				{
					printf("\n %d = %s",i+1,color[i]);
				}
		   		printf("\nInsert the color of the elipse: ");
ecolor_error:	scanf("%d", &e_clr[e_cnt]);
				if(e_clr[e_cnt]<1 || e_clr[e_cnt]>15)
				{
					printf("\nPlease Insert color between 1-15: ");
					goto ecolor_error;
				}
				else
				{
				    printf("\nPlease insert the thickness of the elipse: ");
ethickness_error:	scanf("%d",&e_thick[e_cnt]);
				    if(e_thick[e_cnt]<1)
				    {
				    	printf("Please input more than 0: ");
				    	goto ethickness_error;
					}
					else
					{
				   	drawelipse(xe[e_cnt],ye[e_cnt],d1[e_cnt],d2[e_cnt],e_clr[e_cnt],e_thick[e_cnt]);
				   	e_stats[e_cnt] = true;
				   	e_cnt++;
				   	}
				}
	   break;
	   case 3:
	   		cleardevice();
	   		for(i=0;i<20;i++)
	   		{
		   		xc[i] = 0;
		   		yc[i] = 0;
		   		r[i] = 0;
		   		c_clr[i] = 0;
		   		c_thick[i]=0;
		   		xe[i] = 0;
		   		ye[i] = 0;
		   		d1[i] = 0;
		   		d2[i] = 0;
		   		e_clr[i] = 0;
		   		e_thick[i]=0;
		   		c_stats[i] = false;
		   		e_stats[i] = false;
		   		c_cnt = 0;
		   		e_cnt = 0;
	   		}
	   break;
	   case 4:             //Refresh Screen (Re-draw circle and elips)
	   		for(i=0;i<c_cnt;i++)
	   		{
	   			if(!c_stats[i])
				{
					
				}
				else
				{
					drawcircle(xc[i],yc[i],r[i],c_clr[i],c_thick[i]);	
				}	
			}
			for(i=0;i<e_cnt;i++)
	   		{
	   			if(!e_stats[i])
				{
					
				}
				else
				{
					drawelipse(xe[i],ye[i],d1[i],d2[i],e_clr[i],e_thick[e_cnt]);	
				}	
			}
	   break;
	   case 5:               //Edit Circle
	   		if(c_cnt==0)
	   		{
	   			system("cls");
	   			printf("You don't have any circle in the screen, please draw one\n");	
			}
			else
			{
c_error:		for(i=0;i<20;i++)
				{
					if(c_stats[i] && c_clr[i] != 0)
					{
						temp=c_clr[i]-1;
						printf("\n%d. X-axis = %d, Y-axis = %d, Radius = %d, Color = %s, Thickness = %d", i+1, xc[i], yc[i], r[i], color[temp], c_thick[i]);	
					}
					else
					{
						printf("\n%d. Empty Slot",i+1);	
					}
				}
				printf("\nWhich circle you want to edit: ");
				scanf("%d",&c_input);
				c_input -=1;
				system("cls");
				if(!c_stats[c_input])
				{
					printf("There are no circle in this slot");
					goto c_error;
				}
				else
				{
					temp = c_clr[c_input]-1;
					printf("\n X-axis = %d, Y-axis = %d, Radius = %d, Color = %s, Thickness = %d", xc[c_input], yc[c_input], r[c_input], color[temp], c_thick[c_input]);
					printf("\n1. Delete Circle");
					printf("\n2. Change color");
					printf("\nPlease input your command (number): ");
					scanf("%d", &c_edit);
					switch(c_edit)
					{
						case 1:
							drawcircle(xc[c_input],yc[c_input],r[c_input],0,c_thick[c_input]);
							c_stats[c_input] = false;
							c_cnt -= 1;
							for(i=c_input;i<c_cnt;i++)
							{
								if(!c_stats[i])
								{
									xc[i] = xc[i+1];
									yc[i] = yc[i+1];
									r[i]  = r[i+1];
									c_clr[i] = c_clr[i+1];
									c_thick[i] = c_thick[i+1];
									c_stats[i] = true;
									c_stats[i+1] = false;
									xc[i+1] = 0;
									yc[i+1] = 0;
									r[i+1] = 0;
									c_clr[i+1] = 0;
									c_thick[i+1] = 0;
								}
							}
							break;
						case 2:
							for(i=0;i<15;i++)
							{
								printf("\n %d = %s",i+1,color[i]);
							}
							printf("\n What will be the color (number): ");
subc_error:					scanf("%d", &c_subedit);
							if(c_subedit<1 || c_subedit>15)
							{
								printf("\nPlease Input the color between 1-15: ");
								goto subc_error;
							}
							else
							{
								c_clr[c_input] = c_subedit;
								drawcircle(xc[c_input],yc[c_input],r[c_input],c_subedit,c_thick[c_input]);
							}
					}
				}
				system("cls");	
			}
	   system("pause");
	   break;
	   case 6:
		   	if(e_cnt==0)
	   		{
	   			system("cls");
	   			printf("You don't have any elipse in the screen, please draw one\n");	
			}
			else
			{
e_error:		for(i=0;i<20;i++)
				{
					if(e_stats[i] && e_clr[i] != 0)
					{
						temp=e_clr[i]-1;
						printf("\n%d. X-axis = %d, Y-axis = %d, First diagonal = %d, Second diagonal = %d, Color = %s, Thickness = %d", i+1, xe[i], ye[i], d1[i], d2[i], color[temp], e_thick[i]);	
					}
					else
					{
						printf("\n%d. Empty Slot",i+1);	
					}
				}
				printf("\nWhich elipse you want to edit: ");
				scanf("%d",&e_input);
				e_input -=1;
				system("cls");
				if(!e_stats[e_input])
				{
					printf("There are no elipse in this slot");
					goto e_error;
				}
				else
				{
					temp=e_clr[e_input]-1;
					printf("\n X-axis = %d, Y-axis = %d, First diagonal = %d, Second diagonal = %d, Color = %s, Thickness = %d", xe[e_input], ye[e_input], d1[e_input], d2[e_input], color[temp], e_thick[e_input]);
					printf("\n1. Delete elipse");
					printf("\n2. Change color");
					printf("\nPlease input your command (number): ");
					scanf("%d", &e_edit);
					switch(e_edit)
					{
						case 1:
							drawelipse(xe[e_input],ye[e_input],d1[e_input],d2[e_input],0,e_thick[e_input]);
							e_stats[e_input] = false;
							e_cnt -= 1;
							for(i=e_input;i<e_cnt;i++)
							{
								if(!e_stats[i])
								{
									xe[i] = xe[i+1];
									ye[i] = ye[i+1];
									d1[i] = d1[i+1];
									d2[i] = d2[i+1];
									e_clr[i] = e_clr[i+1];
									e_thick[i] = e_thick[i+1];
									e_stats[i] = true;
									e_stats[i+1] = false;
									xe[i+1] = 0;
									ye[i+1] = 0;
									d1[i+1] = 0;
									d2[i+1] = 0;
									e_clr[i+1] = 0;
									e_thick[i+1] = 0;
								}
							}
						break;
						case 2:
							for(i=0;i<15;i++)
							{
								printf("\n %d = %s",i+1,color[i]);
							}
							printf("\n What will be the color (number): ");
sube_error:				  	scanf("%d", &e_subedit);
							if(e_subedit<1 || e_subedit>15)
							{
								printf("\nPlease input the color 1-15(Based on the menu): ");
								goto sube_error;
							}
							else
							{
							e_clr[e_input] = e_subedit;
							drawelipse(xe[e_input],ye[e_input],d1[e_input],d2[e_input],e_subedit,e_thick[e_input]);
							}
					}
				}
			}
       system("pause");
	   break;
       case 7:
       	    closegraph();
       		system("exit");
       break;
	   }
	   system("cls");
   }
}
