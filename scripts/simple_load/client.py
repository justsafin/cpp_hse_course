import socket
import neuro_pb2
import base64
from timeit import default_timer as timer
from datetime import timedelta


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


def decode_data(data):
    # Create an instance of your protobuf message
    message = neuro_pb2.NeuroAnswer()

    # Decode the base64 to protobuf bytes 
    decoded = base64.standard_b64decode(data)

    source_protobuf = message.ParseFromString(decoded)

    return message.embedding


def fetch_data(socket, buffer_size=4096):
    response = b""
    while True:
        data = socket.recv(buffer_size)
        if not data:
            break
        response += data
    return response


def calculate_stistics(response_times):
    mean = sum(response_times, timedelta())/len(response_times)
    print(f"avg_time = {mean}")
    max_time = max(response_times)
    print(f"max_time = {max_time}")
    min_time = min(response_times)
    print(f"min_time = {min_time}")

    rps = 1/(mean.microseconds) * 1000000
    print(f"{rps=}")

def main():
    host = "localhost"
    port = 12345
    response_times = []
    c = 0
    errors_c = 0

    try:
        file = open("text_data.txt", "r")
        line = file.readline()
        while line:
            c += 1
            try:
                b64_line = encode_data(c, line) + b"\n"
                with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                    start = timer()
                    s.connect((host, port))
                    s.sendall(b64_line)
                    response = fetch_data(s)
                    response_times.append(timedelta(seconds=timer()-start))
                    decodet_data = decode_data(response)
                    # print("data ", decodet_data)
            except socket.timeout:
                errors_c += 1    
            finally:
                line = file.readline()
    except KeyboardInterrupt:
        print("Client exited")
    finally:
        file.close()
        calculate_stistics(response_times)


if __name__ == "__main__":
    main()