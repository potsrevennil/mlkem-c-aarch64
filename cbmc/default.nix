# SPDX-License-Identifier: Apache-2.0
{ cbmc
, fetchFromGitHub
, callPackage
, z3_4_12
, bitwuzla
, ninja
, cadical
}:
builtins.attrValues {
  cbmc = cbmc.overrideAttrs (old: rec {
    version = "6.3.1"; # remember to adjust this in ../flake.nix too
    src = fetchFromGitHub {
      owner = "diffblue";
      repo = old.pname;
      rev = "${old.pname}-${version}";
      hash = "sha256-y3avPsVxtxSV+WB8TBbvnaNZ4WZltGRTcD+GPwTlp2E=";
    };
    patches = [
      ./0001-Do-not-download-sources-in-cmake.patch
    ];
  });
  litani = callPackage ./litani.nix { }; # 1.29.0
  cbmc-viewer = callPackage ./cbmc-viewer.nix { }; # 3.9

  inherit
    ninja# 1.11.1
    z3_4_12# 4.12.5
    cadical#1.9.5
    bitwuzla; # 0.4.0
}
