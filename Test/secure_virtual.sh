name="$(getent passwd $(whoami) | awk -F: '{print $5}')"
out_dir='/root/module-signing'
sudo openssl \
    req \
    -new \
    -x509 \
    -newkey \
    rsa:2048 \
    -keyout ${out_dir}/MOK.priv \
    -outform DER \
    -out ${out_dir}/MOK.der \
    -days 36500 \  # This is probably waaay too long.
    -subj "/CN=florian/"
sudo chmod 600 ${out_dir}/MOK*
