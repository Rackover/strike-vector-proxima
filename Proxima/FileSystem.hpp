#pragma once
namespace Proxima
{
	class FileSystem
	{
	public:
		static bool WriteRemoteStorageFile(const char* name, const char* data, uint32_t length)
		{
			CreateRemoteStorageFolder();
			std::string buffer(data, length);
			return WriteFileInternal(buffer, REMOTE_STORAGE_DIRECTORY_NAME / name);
		}

		static std::string ReadRemoteStorageFile(const char* name, uint32_t maxLength)
		{
			CreateRemoteStorageFolder();
			const auto path = REMOTE_STORAGE_DIRECTORY_NAME / name;
			std::string readBuffer = ReadFileInternal(path);

			return readBuffer.substr(0, min(readBuffer.size(), maxLength));
		}

		static int32 GetRemoteStorageFileSize(const char * name)
		{
			CreateRemoteStorageFolder();
			const auto path = REMOTE_STORAGE_DIRECTORY_NAME / name;

			return static_cast<int32>(GetFileSize(path));
		}

	private:
		static const std::filesystem::path REMOTE_STORAGE_DIRECTORY_NAME;

		static void CreateRemoteStorageFolder();
		static bool WriteFileInternal(const std::string& data, const std::filesystem::path& path);
		static std::string ReadFileInternal(const std::filesystem::path& path);
		static std::streamoff GetFileSize(const std::filesystem::path& path);
	};
}