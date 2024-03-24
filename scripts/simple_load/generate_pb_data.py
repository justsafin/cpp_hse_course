import neuro_pb2
import base64


def encode_data(id, text):
    # Create an instance of your protobuf message
    message = neuro_pb2.NeuroRequest()

    # Populate the fields of the message as needed
    message.qid = id
    message.query = text

    # Serialize the message to protobuf format
    protobuf_bytes = message.SerializeToString()

    # Encode the protobuf bytes to base64
    base64_encoded = base64.b64encode(protobuf_bytes)
    return base64_encoded


if __name__ == "__main__":
    file = open("text_data.txt", "r")
    with open("pb_data_for_keepalive.bin", "wb") as w_file:
        c = 0
        line = file.readline()
        while line:
            if c >= 640:
                break
            words = line.split(" ")
            for word in words:
                b64_line = encode_data(c, word) + b"\n"
                w_file.write(b64_line)
                c += 1
            w_file.write(b"\n")
            line = file.readline()
    
    file.close()