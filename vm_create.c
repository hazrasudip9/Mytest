#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libvirt/libvirt.h>

int main(int argc, char *argv[])
{
virConnectPtr conn;

virDomainPtr dom = NULL;

conn = virConnectOpen("qemu:///system");
if (conn == NULL) {
fprintf(stderr, "Failed to open connection to qemu:///system\n");

}
char domxml[] ="<domain type='kvm'> <name>sudip</name> <uuid>c7a5fdbd-cdaf-9455-926a-d65c16db1809</uuid>  <memory>131072</memory>  <currentMemory>131072</currentMemory>  <vcpu>1</vcpu>  <os>   <type arch='x86_64'>hvm</type>  </os>  <devices>    <emulator>/usr/bin/kvm</emulator>    <disk type='file' device='cdrom'><source file='/var/lib/libvirt/images/ubuntu-13.10-server-amd64.iso'/><target dev='hdc' bus='ide'/></disk> <interface type='network'><source network='default'/></interface><graphics type='vnc' port='-1'/></devices> </domain>";
dom = virDomainCreateXML(conn, domxml, 0);
if (dom == NULL) {
fprintf(stderr, "Failed to create domain\n");

}
printf("Domain Created Successfully\n");
return 0;
}
