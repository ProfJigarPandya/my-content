#!/bin/bash
#!/bin/bash
# Force the system path so the 'hadoop' user can find the 'host' and 'sed' utilities
PATH=$PATH:/usr/bin:/usr/sbin:/bin:/sbin


# Fall back safely if Hadoop sends no arguments
if [ $# -eq 0 ]; then
  echo "/default-rack"
  exit 0
fi

# Process every node argument passed by the NameNode
while [ $# -gt 0 ]; do
  NODE_ARG=$1
  HOSTNAME=""

  # Check if the input is a raw IP address (contains numbers and dots)
  if [[ "$NODE_ARG" =~ ^[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+$ ]]; then
    # Perform a Reverse DNS lookup to find the hostname
    # Grabs the last word of the output, which is the FQDN, and trims trailing dots
    LOOKUP=$(host "$NODE_ARG" | awk '{print $NF}' | sed 's/\.$//')
    
    # Verify the DNS lookup actually returned a valid hostname instead of an error
    if [[ "$LOOKUP" == *"-lab"* ]]; then
      HOSTNAME="$LOOKUP"
    fi
  else
    # The input is already a hostname text string
    HOSTNAME="$NODE_ARG"
  fi

  # Extract the rack name if we have a valid hostname containing "-lab"
  if [[ -n "$HOSTNAME" && "$HOSTNAME" == *"-lab"* ]]; then
    # Extracts "labXX" from "fot-ce-labXX-11"
    #RACK=$(echo "$HOSTNAME" | sed -E 's/.*-(lab[0-9]+)-.*/\1/')
    RACK=$(echo "$HOSTNAME" | sed -E 's/(^.*-lab[0-9]+)-.*/\1/')
    echo "/$RACK"
  else
    # Safety fallback if DNS breaks or name pattern doesn't match
    echo "/default-rack"
  fi

  shift
done

