#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libvirt/libvirt.h>


int main(int argc, char *argv[])
{
virConnectPtr conn;
int i;
int numDomains;
int *activeDomains;
virDomainPtr dom;
conn = virConnectOpen("qemu:///system");
if (conn == NULL) {
fprintf(stderr, "Failed to open connection to qemu:///system\n");
}
numDomains = virConnectNumOfDomains(conn);
activeDomains = malloc(sizeof(int) * numDomains);
numDomains = virConnectListDomains(conn, activeDomains, numDomains);
printf("Active domain IDs:\n");
for (i = 0 ; i < numDomains ; i++) {
printf(" %d\n", activeDomains[i]);
}
printf("Terminating Domain\n");
free(activeDomains);
int domainName = "sudip";
dom = virDomainLookupByName(conn,domainName);
virDomainDestroy(dom);
virDomainFree(dom);
printf("Domain sudip terminated successfully\n");

if (conn != NULL)
virConnectClose(conn);
return 0;
}

