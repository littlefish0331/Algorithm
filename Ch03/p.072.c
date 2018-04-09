//用switch可以!!

#include <stdio.h>
int main(){

    int a, b, c, d, e, f, g, h, i, n;

    scanf("%d", &n);

    if(n==1){
        for(a=1;a<=n;a=a+1){
            printf("%d", a);
        }
    }


    if(n==2){
        for(a=1;a<=n;a=a+1){
            for(b=1;b<=n;b=b+1){
                if(a!=b){
                    printf("%d%d\n",a,b);
                }
            }
        }
    }


    if(n==3){
        for(a=1;a<=n;a=a+1){
            for(b=1;b<=n;b=b+1){
                for(c=1;c<=n;c=c+1){
                    if(a!=b && a!=c && b!=c){
                        printf("%d%d%d\n", a,b,c);
                    }
                }
            }
        }
    }

    if(n==4){
        for(a=1;a<=n;a=a+1){
            for(b=1;b<=n;b=b+1){
                for(c=1;c<=n;c=c+1){
                    for(d=1;d<=n;d=d+1){
                        if(a!=b && a!=c && a!=d
                                && b!=c && b!=d
                                        && c!=d){
                            printf("%d%d%d%d\n", a,b,c,d);
                        }
                    }
                }
            }
        }
    }


    if(n==5){
        for(a=1;a<=n;a=a+1){
            for(b=1;b<=n;b=b+1){
                for(c=1;c<=n;c=c+1){
                    for(d=1;d<=n;d=d+1){
                        for(e=1;e<=n;e=e+1){
                            if(a!=b && a!=c && a!=d && a!=e
                                    && b!=c && b!=d && b!=e
                                            && c!=d && c!=e
                                                    && d!=e){
                                printf("%d%d%d%d%d\n", a,b,c,d,e);
                            }
                        }
                    }
                }
            }
        }
    }

    if(n==6){
        for(a=1;a<=n;a=a+1){
            for(b=1;b<=n;b=b+1){
                for(c=1;c<=n;c=c+1){
                    for(d=1;d<=n;d=d+1){
                        for(e=1;e<=n;e=e+1){
                            for(f=1;f<=n;f=f+1){
                                if(a!=b && a!=c && a!=d && a!=e && a!=f
                                        && b!=c && b!=d && b!=e && b!=f
                                                && c!=d && c!=e && c!=f
                                                        && d!=e && d!=f
                                                                && e!=f){
                                    printf("%d%d%d%d%d%d\n", a,b,c,d,e,f);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if(n==7){
        for(a=1;a<=n;a=a+1){
            for(b=1;b<=n;b=b+1){
                for(c=1;c<=n;c=c+1){
                    for(d=1;d<=n;d=d+1){
                        for(e=1;e<=n;e=e+1){
                            for(f=1;f<=n;f=f+1){
                                for(g=1;g<=n;g=g+1){
                                    if(a!=b && a!=c && a!=d && a!=e && a!=f && a!=g
                                            && b!=c && b!=d && b!=e && b!=f && b!=g
                                                    && c!=d && c!=e && c!=f && c!=g
                                                            && d!=e && d!=f && d!=g
                                                                    && e!=f && e!=g
                                                                            && f!=g){
                                        printf("%d%d%d%d%d%d%d\n", a,b,c,d,e,f,g);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    if(n==8){
        for(a=1;a<=n;a=a+1){
            for(b=1;b<=n;b=b+1){
                for(c=1;c<=n;c=c+1){
                    for(d=1;d<=n;d=d+1){
                        for(e=1;e<=n;e=e+1){
                            for(f=1;f<=n;f=f+1){
                                for(g=1;g<=n;g=g+1){
                                    for(h=1;h<=n;h=h+1){
                                        if(a!=b && a!=c && a!=d && a!=e && a!=f && a!=g && a!=h
                                                && b!=c && b!=d && b!=e && b!=f && b!=g && b!=h
                                                        && c!=d && c!=e && c!=f && c!=g && c!=h
                                                                && d!=e && d!=f && d!=g && d!=h
                                                                        && e!=f && e!=g && e!=h
                                                                                && f!=g && f!=h
                                                                                        && g!=h){
                                            printf("%d%d%d%d%d%d%d%d\n", a,b,c,d,e,f,g,h);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    if(n==9){
        for(a=1;a<=n;a=a+1){
            for(b=1;b<=n;b=b+1){
                for(c=1;c<=n;c=c+1){
                    for(d=1;d<=n;d=d+1){
                        for(e=1;e<=n;e=e+1){
                            for(f=1;f<=n;f=f+1){
                                for(g=1;g<=n;g=g+1){
                                    for(h=1;h<=n;h=h+1){
                                        for(i=1;i<=n;i=i+1){
                                            if(a!=b && a!=c && a!=d && a!=e && a!=f && a!=g && a!=h && a!=i
                                                    && b!=c && b!=d && b!=e && b!=f && b!=g && b!=h && b!=i
                                                            && c!=d && c!=e && c!=f && c!=g && c!=h && c!=i
                                                                    && d!=e && d!=f && d!=g && d!=h && d!=i
                                                                            && e!=f && e!=g && e!=h && e!=i
                                                                                    && f!=g && f!=h && f!=i
                                                                                            && g!=h && g!=i
                                                                                                    && h!=i){
                                                printf("%d%d%d%d%d%d%d%d%d\n", a,b,c,d,e,f,g,h,i);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }




}


